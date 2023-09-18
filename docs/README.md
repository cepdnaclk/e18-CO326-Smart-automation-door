---
layout: home
permalink: index.html

# Please update this with your repository name and title
repository-name: e18-CO326-Smart-automation-door
title: Smart-automation-door
---

[comment]: # "This is the standard layout for the project, but you can clean this and use your own template"

# Smart Secured Door

---

<!-- 
This is a sample image, to show how to add images to your page. To learn more options, please refer [this](https://projects.ce.pdn.ac.lk/docs/faq/how-to-add-an-image/)

![Sample Image](./images/sample.png)
 -->

## Team
-  E/18/068, G.C. Devinda, [e18068@pdn.ac.lk](mailto:name@email.com)
-  E/18/073, W.M.T. Dhananjaya, [e18073@pdn.ac.lk](mailto:name@email.com)
-  E/18/214, H.K. Manahara, [e18214@pdn.ac.lk](mailto:name@email.com)

## Table of Contents
1. [Introduction](#introduction)
2. [Overview](#overview)
3. [Hardware Deign](#hardware)
4. [Scada logic](#scada)
5. [Links](#links)

---

## Introduction

Welcome to the GitHub page for "Smart Secured Auto Door," where we introduce a groundbreaking solution designed to excel in occupancy management, enhance security and safety, provide valuable analytics and insights, and boost automation and efficiency. Our core objectives encompass creating a system that adeptly manages occupancy, safeguarding spaces for authorized users, and employing advanced access control mechanisms to heighten security and ensure occupant safety. Leveraging hardware components like the HC-SR501 PIR Motion Sensor, Servo Motor, and ESP-32S microcontroller, our project orchestrates seamless control of doors, automating access based on occupancy, thereby reducing manual intervention and improving overall efficiency. We rely on the Mosquitto broker for streamlined communication between project components, while a MySQL database forms the foundation for storing and managing vital data related to occupancy, access control, and analytical insights. Explore our GitHub repository to delve into the source code, documentation, and setup instructions, whether you aim to contribute to development or deploy this innovative solution for your specific needs. Join us in revolutionizing occupancy management and access control systems, as we embark on a journey towards a safer, smarter world with the "Smart Secured Auto Door" project.

## Overview

The "Smart Secured Auto Door" project is an innovative system designed to address key aspects of modern space management and access control. Its primary objectives are to efficiently manage occupancy, enhance security and safety, gather valuable analytics and insights, and improve overall automation and efficiency.

To achieve these goals, the project utilizes a combination of hardware components, including the HC-SR501 PIR Motion Sensor for motion detection, a Servo Motor for automated door control, and the ESP-32S microcontroller to process data and manage system operations. Communication between these components is facilitated by the Mosquitto broker, a lightweight MQTT protocol-based messaging system, ensuring seamless coordination.

In addition, the project relies on a MySQL database to store and manage essential data related to occupancy, access control, and analytics. This database serves as the central repository for collecting and retrieving information crucial to the system's functionalities.

Whether you're interested in contributing to the project's development or implementing it for your specific needs, the GitHub repository provides access to the project's source code, documentation, and setup instructions. With the "Smart Secured Auto Door," we aim to create a safer, more efficient, and smarter world by redefining occupancy management and access control systems.


## Hardware Design
![Picture1](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/da816c3b-c1bc-4556-bc26-8b1dfee6bd49)

### HC-SR501 (PIR Motion Sensor)
![Picture3](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/e51088ec-9efe-46fe-82a7-987d6acfe1e5)

The HC-SR501 is a Passive Infrared (PIR) motion sensor module. It is designed to detect motion in its vicinity by sensing changes in infrared radiation levels. PIR sensors are commonly used in various applications, including security systems, automated lighting, and, in this case, occupancy detection for doors. When motion is detected, the sensor sends a signal to the microcontroller (ESP-32S in this project), indicating that movement has been sensed in the monitored area. This data is then used to trigger actions such as opening or closing the door, enhancing security and automation.

### Servo Motor
![Picture4](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/a9cd2327-63b0-4955-9935-5360c7f4e991)


A servo motor is a type of rotary actuator that can precisely control the position of its output shaft. In the "Smart Secured Auto Door" project, the servo motor is responsible for controlling the movement of the door. By receiving commands from the microcontroller (ESP-32S), the servo motor can open and close the door as needed. Servo motors are commonly used in robotics, automation, and various mechatronic applications due to their accuracy and ability to maintain a specific position.

### ESP-32S
![Picture5](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/ee9c350a-6d5c-410d-8a38-8b8eff09ccab)


The ESP-32S is a powerful microcontroller based on the ESP32 system-on-chip (SoC). It is widely used in Internet of Things (IoT) projects due to its built-in Wi-Fi and Bluetooth capabilities, as well as its processing power and versatility. In the "Smart Secured Auto Door" project, the ESP-32S serves as the brain of the system. It receives data from the PIR motion sensor, processes this data to determine whether someone is approaching the door, and controls the servo motor to open or close the door accordingly. Additionally, it can communicate with other devices or systems through Wi-Fi or Bluetooth, making it a key component for IoT-based access control and occupancy management.


## Scada Logic
![Picture2](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/e19f53bd-0f0c-4829-9576-bfa892babe43)

## Scada UI Design
![Picture6](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/440e6878-176d-4074-84df-b823d7d4bb12)

## System Design
![WhatsApp Image 2023-09-18 at 23 42 41](https://github.com/cepdnaclk/e18-CO326-Smart-automation-door/assets/73760543/1df50ed6-76e2-40e6-a891-1ec4c5a0d65a)


.....

## Links

- [Project Repository](https://github.com/cepdnaclk/{{ page.repository-name }}){:target="_blank"}
- [Project Page](https://cepdnaclk.github.io/{{ page.repository-name}}){:target="_blank"}
- [Department of Computer Engineering](http://www.ce.pdn.ac.lk/)
- [University of Peradeniya](https://eng.pdn.ac.lk/)


[//]: # (Please refer this to learn more about Markdown syntax)
[//]: # (https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
