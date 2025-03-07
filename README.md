# Brushless DC Motor PID Controller by Arduino UNO - Fall 2023
In this project, the course project of Applied Electronics at SUT, we control speed of a brushless DC motor using PID controller.
We use IR FC51 infrared sensor for getting speed feedback from propellers attached to the DC motor. Huge shout out to my dear friend [Reyhane Nikoobayan](https://github.com/ReyhaneNikoobayan) for her contributions in this project.

<img src="https://github.com/user-attachments/assets/95526af3-c7f4-4021-9374-ed07e63f4345" width="400" class="center"/>

Arduino Uno processes information and outputs controll signals to L298 drive.

<img src="https://github.com/user-attachments/assets/eda08de3-e0d7-4142-952e-e60b7378017b" width="400" class="center"/>

Here, you can see the complete configuration of our system.

<img src="https://github.com/user-attachments/assets/885832d3-7cfd-456a-8447-e0bae7764bad" width="500" class="center"/>

## This project contains:
- `main_serial` - Source code for Arduino IDE using serial as user interface
- `main_wifi` - Source code for Arduino IDE using wifi connection and an android system as user interface
- IR approximity sensor
- DC motor
- PID tuning on hardware
- Varying setpoints


