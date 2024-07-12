# Gesture Controlled Robotic Vehicle 
## Project Overview
Gesture Controlled Car is a robot which can be controlled by simple human gestures. This is an Arduino based gesture-controlled car that takes readings from an accelerometer which is placed on a human hand. 
The direction of the car can be changed by moving the hand in a particular direction, each movement generates the values in its corresponding axis. 
This project can be very helpful for physically challenged people as they can move certain objects with less physical movement.

![image](https://github.com/user-attachments/assets/7edf7443-51b3-4085-8950-28061e6e98a6)

## Flow Chart
When a gesture is made by the user the MPU-6050 values are mapped by Arduino pro mini (Transmitter). The transmitter controller encodes this value as string and transmits it to Receiving Arduino through 433MHZ transmitter module. 
The receiving Arduino receives the data through 433MHZ Receiver module. When the data is received its in-String Format. The controller converts this “String” into “INT” and then as per the program it controls the car “FORWARD”, “BACKWARD”, “LEFT”, Or “RIGHT”.

![image](https://github.com/user-attachments/assets/b849efde-3178-4420-b335-d77020315af6)
