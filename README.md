# Arduino Sun Tracking Solar Panel

## Project Overview
A college mini project completed in May 2023 to explore automatic solar panel positioning using an Arduino Uno, two LDR sensors, and a servo motor.

This repository contains a recreated Arduino firmware implementation based on the project's concept.

## Hardware Components
- Arduino Uno
- 2 Light Dependent Resistors (LDRs)
- 1 servo motor
- 2 x 10 kΩ resistors for LDR voltage dividers
- Solar panel and connecting wires

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Left LDR output | A0 |
| Right LDR output | A1 |
| Servo signal | D9 |

## Working Principle
1. The Arduino reads the two LDR sensor values.
2. The firmware compares the readings to estimate the brighter direction.
3. The servo angle is adjusted based on the difference between the readings.
4. Sensor readings and servo position are printed to the Serial Monitor at 9600 baud.

## Software
- Arduino IDE
- Arduino C/C++
- Servo library

## Repository Structure
- `src/sun_tracking.ino` - Arduino tracking firmware

## Testing Status
Hardware testing status: Not yet verified.

## Learning Outcomes
- Analog sensor interfacing
- Microcontroller programming
- Servo motor control
- Sensor-based decision logic
- Embedded hardware-software integration

## Project Details
- Project type: College mini project
- Original project period: May 2023
- Firmware in this repository: Recreated implementation
