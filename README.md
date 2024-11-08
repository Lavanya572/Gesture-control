# Gesture Controlled Robotic Vehicle 
## Project Overview
Gesture Controlled Car is a robot which can be controlled by simple human gestures. This is an Arduino based gesture-controlled car that takes readings from an accelerometer which is placed on a human hand. 
The direction of the car can be changed by moving the hand in a particular direction, each movement generates the values in its corresponding axis. 
This project can be very helpful for physically challenged people as they can move certain objects with less physical movement.

## Features
- Gesture-Based Control: Uses hand gestures for navigation, reducing manual intervention.
- High Accuracy: Achieved 90% accuracy in real-time movement based on gesture input.
- Wireless Communication: Transmits data from the gesture sensor to the vehicle via radio communication.


## Getting Started
### Prerequisites
#### Hardware:
- Arduino Mega or Pro Mini (for vehicle control)
- Accelerometer (for gesture sensing)
- Radio communication modules (e.g., RF module for data transmission)
#### Software:
- Arduino IDE for code development and deployment.

## Working
When a gesture is made by the user the MPU-6050 values are mapped by Arduino pro mini (Transmitter). The transmitter controller encodes this value as string and transmits it to Receiving Arduino through 433MHZ transmitter module. 
The receiving Arduino receives the data through 433MHZ Receiver module. When the data is received its in-String Format. The controller converts this “String” into “INT” and then as per the program it controls the car “FORWARD”, “BACKWARD”, “LEFT”, Or “RIGHT”.

## Technologies Used
- Arduino IDE: Code development for interpreting gestures and controlling the vehicle.
- Accelerometer: Captures hand movements and converts them into navigational commands.
- Radio Communication: Facilitates wireless communication between the gesture controller and the vehicle.


