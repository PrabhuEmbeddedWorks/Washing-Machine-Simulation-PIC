# PIC16F877A Washing Machine Simulation

This repository contains the simulation of an **Automatic Washing Machine Controller** implemented using the **PIC16F877A microcontroller**.  
The project is developed in **Embedded C** using **MPLAB X IDE** and simulated using **PicSimLab**.

The objective of this project is to demonstrate real-world embedded system design concepts such as **state machines, timer interrupts, keypad-based user interaction, LCD interfacing, and safety mechanisms**, commonly used in household appliances.

---

## Project Demonstration

A complete working simulation of the project is available on YouTube:

🔗 https://youtu.be/_nmZ3aQhsrw

---

## Features

- Keypad-based software-controlled Power ON
- LCD-based power-on visualization
- Washing program selection
- Water level selection
- Start, Pause, and Resume functionality
- Timer-driven wash, rinse, and spin operations
- Door open safety detection
- Buzzer alert on program completion
- State-machine-based system flow

---

## System Overview

The washing machine controller operates as a finite state machine with the following major states:

1. Power ON state
2. Washing program selection
3. Water level selection
4. Start / Stop control
5. Washing operation (Wash / Rinse / Spin)
6. Pause and Resume
7. Safety handling (door open)
8. Program completion

Each state transition is controlled through keypad inputs and internal timing logic.

---

## Hardware / Simulation Setup

- **Microcontroller:** PIC16F877A  
- **Display:** 16x4 Character LCD (HD44780 compatible)  
- **Input:** Matrix Keypad (PORTB)  
- **Timer:** Timer2 with Interrupt Service Routine  
- **Outputs:** Fan (motor simulation), Buzzer  
- **Simulation Tool:** PicSimLab (PICGenios board)

---

## Software Tools Used

- MPLAB X IDE
- XC8 Compiler
- PicSimLab Simulator
- Embedded C

---

## Key Concepts Demonstrated

- Embedded C programming
- GPIO configuration and usage
- LCD interfacing
- Matrix keypad scanning
- Timer configuration and ISR handling
- State machine based control logic
- Real-time embedded system behavior
- Safety-critical embedded design

---

## Project Structure

```

PIC16F877A-Washing-Machine-Simulation/
│
├── main.c
├── clcd.c
├── clcd.h
├── digital_keypad.c
├── digital_keypad.h
├── timers.c
├── timers.h
├── washing_machine_function_def.c
├── washing_machine_function_def.h
└── README.md

```

---

## How to Run the Project

1. Open the project in **MPLAB X IDE**
2. Select **PIC16F877A** as the target device
3. Build the project using the **XC8 compiler**
4. Load the generated `.hex` file into **PicSimLab**
5. Start simulation and interact using the keypad

---

## Applications

- Embedded Systems Mini / Final Year Project
- Microcontroller laboratory experiments
- Interview and viva demonstrations
- Learning real-time embedded system design
- Appliance control system simulation

---

## Author

Developed as an Embedded Systems project using PIC microcontroller and Embedded C.

---

## License

This project is intended for educational and learning purposes.
```

---
