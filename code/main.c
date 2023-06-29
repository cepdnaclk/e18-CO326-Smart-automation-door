#include <stdbool.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


bool True = true;

// PIR sensor pin
const int pirPin = 14;    // D5
// Bulb pin
const int bulbPin = 4;    // D2
// Servo motor pin
const int servoPin = 2;   // D4
// Buzzer pin
const int buzzerPin = 12; // D6

// WiFi credentials
const char* ssid = "Dialog Hotspot";
const char* password = "D176556EBTT";

// MQTT broker details
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

Servo servo;  // Create a servo object

int motionDetectionCount = 0; // Counter for motion detection events

void setup() {
  pinMode(pirPin, INPUT);          // Initialize PIR sensor pin as INPUT
  pinMode(bulbPin, OUTPUT);        // Initialize bulb pin as OUTPUT
  pinMode(buzzerPin, OUTPUT);      // Initialize buzzer pin as OUTPUT

  servo.attach(servoPin);          // Attach the servo to the servo pin
  servo.write(0);                  // Set the initial position of the servo to 0 degrees

  setupWiFi();
  connectToMQTT();
}

void loop() {
  if (!mqttClient.connected()) {
    reconnectMQTT();
  }
  mqttClient.loop();

  int pirValue = digitalRead(pirPin);  // Read the PIR sensor value

  if (pirValue == HIGH) {
    digitalWrite(bulbPin, HIGH);       // Turn on the bulb
    servo.write(180);                   // Rotate the servo to 90 degrees
    tone(buzzerPin, 1000);              // Generate a tone of 1000Hz on the buzzer

    // Publish the detection event to the MQTT broker
    mqttClient.publish("test", "Motion Detected");
    motionDetectionCount++; // Increment the motion detection count
    sendCountToMQTT(); // Send the count to MQTT
  } else {
    digitalWrite(bulbPin, LOW);        // Turn off the bulb
    servo.write(0);                    // Rotate the servo to 0 degrees
    noTone(buzzerPin);                  // Stop generating the tone on the buzzer
  }
  
  delay(100);  // Delay for stability or adjust as per your requirements
}

void setupWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
}

void connectToMQTT() {
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(mqttCallback);

  while (!mqttClient.connected()) {
    if (mqttClient.connect("ESP8266Client", mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT broker");
      mqttClient.subscribe("test/count_topic"); // Subscribe to the count topic
    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void reconnectMQTT() {
  while (!mqttClient.connected()) {
    if (mqttClient.connect("ESP8266Client", mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT broker");
      mqttClient.subscribe("test/count_topic"); // Subscribe to the count topic
    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  // Convert the payload to a string
  char message[length + 1];
  memcpy(message, payload, length);
  message[length] = '\0';

  // Print the received topic and message
  Serial.print("Received message on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  Serial.println(message);

  // Add your custom logic here to handle the received MQTT message
  // For example, you can check the topic and perform specific actions based on the message content

  // Example: Toggle the bulb state if the topic is "test/bulb_control_topic"
  if (strcmp(topic, "test/bulb_control_topic") == 0) {
    if (strcmp(message, "ON") == 0) {
      digitalWrite(bulbPin, HIGH);  // Turn on the bulb
    } else if (strcmp(message, "OFF") == 0) {
      digitalWrite(bulbPin, LOW);   // Turn off the bulb
    }
  }
  
  // Handle count message received
  if (strcmp(topic, "test/count_topic") == 0) {
    // Convert the message to an integer
    int count = atoi(message);
    // Set the motion detection count to the received value
    motionDetectionCount = count;
    // Print the updated count
    Serial.print("Motion Detection Count: ");
    Serial.println(motionDetectionCount);
  }
}

void sendCountToMQTT() {
  char countMessage[10];
  sprintf(countMessage, "%d", motionDetectionCount);
  mqttClient.publish("test/count_topic", countMessage);
}
