# Automatic Bike Side Stand Slider

An Arduino-based embedded system designed to enhance motorcycle rider safety by preventing accidents caused by a forgotten or improperly retracted side stand.

## How It Works
1. **Speed Detection:** A Hall-effect sensor monitors wheel rotation.
2. **Microcontroller Logic:** When the speed exceeds **10 km/h**, the Arduino Uno processes the sensor data.
3. **Automatic Actuation:** If the stand is still down, the Arduino signals the **L298N motor driver** to run a **Brushed DC motor**, retracting the stand automatically.
4. **Precision Control:** Dual **limit switches** act as position sensors to cut power when the stand is fully extended or retracted, preventing mechanical strain.

## Hardware Components
* Arduino UNO R3
* L298N Motor Driver
* Hall Effect Speed Sensor
* Brushed DC Geared Motor
* Limit Switches (x2)
* LM7805 Voltage Regulator (Steps down the bike's 12V battery to 5V)

## Circuit Diagram
![Circuit Diagram](hardware/circuit_diagram.png) *(Make sure your file path matches exactly)*

