# Automatic Bike Side Stand Slider

An innovative, mechatronics-driven motorcycle safety system that utilizes an Arduino UNO, a Hall-effect speed sensor, and an L298N motor driver to automatically retract the side stand via a Brushed DC motor when the vehicle's speed crosses a critical threshold. By eliminating reliance on human memory, this embedded system completely mitigates the risk of accidents caused by riding with a deployed side stand.

---

## 🛠️ Hardware Prototyping & System Integration
| Circuit Framework | System Architecture Flowchart |
| :---: | :---: |
| ![Circuit Diagram](hardware/circuit_diagram.png) | ![Architecture Flow](hardware/architecture_flow.png) |

---

## 🚀 Features
* **Intelligent Speed Thresholding:** Continuously monitors wheel rotation using a non-contact Hall-effect sensor and triggers retraction precisely when speed exceeds **10 km/h**.
* **Dual-Switch Position Feedback:** Incorporates localized limit switches to act as closed-loop position sensors, instantly cutting motor power at terminal travel positions to eliminate mechanical strain and gear binding.
* **Fail-Safe Manual Override:** The system ensures the side stand is never mechanically locked into place, preserving standard manual deployment capabilities when stationary.
* **Seamless Power Integration:** Powered entirely by the motorcycle’s native **12V battery**, stepping down to a stable **5V logic supply** via an LM7805 regulator without interfering with core vehicle electrical lines.

---

## 🛠️ System Architecture
The system relies on a unified microcontroller setup managing real-time sensor polling and high-current motor actuation loops:
* **Controller (Arduino UNO R3):** Acts as the central processing unit, utilizing digital interrupts/de-bouncing logic to parse sensor frequency pulses into calculated velocity states.
* **Actuation Interface (L298N Dual H-Bridge):** Functions as a current amplifier to switch direction and isolate the logic controller from the high-current demands of the physical actuator.
* **Drivetrain Actuator:** A high-torque Brushed DC geared motor linked via mechanical coupling to slide or pivot the structural stand assembly smoothly.

---

## 💻 Tech Stack & Dependencies
* **Core Language:** C++ (Arduino Wiring Framework)
* **Development Environment:** Arduino IDE v1.8.13+
* **Core Logic Modules:** High-current H-bridge commutation, hardware de-bouncing, and terminal limit sensing.

---

## 📅 Project Roadmap
- [x] Configure LM7805 voltage step-down topology for automotive battery filtering.
- [x] Implement Hall-effect pulse counting with logic de-bouncing. (Code deployed in `arduino/`)
- [x] Integrate dual limit-switch state tracking to establish absolute safety stops.
- [x] Optimize actuation runtime thresholding from 10 cycles down to a high-response 5-cycle window.
