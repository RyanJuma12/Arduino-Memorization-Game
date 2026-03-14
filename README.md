# Arduino Memory Game (Simon-Style Game)  

![Arduino](https://img.shields.io/badge/Arduino-Project-blue)  

---

## Project Overview  

The **Arduino Memory Game** is a game where the player must repeat an increasingly growing sequence of LED flashes.  

**Features:**  
- LEDs flash in a random sequence.  
- Player repeats the sequence using buttons.  
- Buzzer provides audio feedback for correct or incorrect presses.  
- LCD1602 displays game messages, level, and score.  

This project demonstrates **embedded systems programming, state machines, button debouncing, and hardware integration** using Arduino Mega.

---

## Features  

- 4 LEDs and 4 buttons for interactive gameplay.  
- LCD1602 display showing instructions, “Your Turn,” and Game Over messages.  
- Buzzer feedback: different tones for each LED and a “lose” tone.  
- Level progression with dynamic difficulty (faster LED flashes as level increases).  
- Reliable button handling with **debouncing** and **fresh-press detection**.  
- Modular, state-machine-based code for maintainability.  

---

## Hardware Requirements  

| Component         | Quantity | Notes                                      |
|------------------|----------|--------------------------------------------|
| Arduino Mega 2560 | 1        | Main microcontroller                        |
| LED               | 4        | Connect through 220Ω resistors              |
| Pushbutton        | 4        | Normally open, wired with pull-ups          |
| Buzzer            | 1        | Active or passive                           |
| LCD1602 Display   | 1        | 16x2 with parallel interface                |
| Potentiometer     | 1        | For LCD contrast adjustment                 |
| Resistors         | 4        | 220Ω for LEDs                               |
| Jumper wires      | -        | For all connections                         |
| Breadboard        | 1        | Optional for prototyping                    |

---

## Circuit Wiring  

**LEDs:**  
## Step 1: Connect the LEDs

| LED | Arduino Pin | Resistor | LED Pin | Connect LED Cathode |
|-----|------------|----------|---------|------------------|
| LED1 | D6 | 220Ω | Anode (+) | GND |
| LED2 | D7 | 220Ω | Anode (+) | GND |
| LED3 | D8 | 220Ω | Anode (+) | GND |
| LED4 | D9 | 220Ω | Anode (+) | GND |

**Instructions:**  
- Connect **Arduino digital pin → 220Ω resistor → LED anode (+)**.  
- Connect **LED cathode (-) → GND**.  

---

## Step 2: Connect the Pushbuttons

| Button | Arduino Pin | Other Terminal |
|--------|------------|----------------|
| Button1 | A0 | GND |
| Button2 | A1 | GND |
| Button3 | A2 | GND |
| Button4 | A3 | GND |

**Notes:**  
- Buttons use **INPUT_PULLUP** in code, so connect the other terminal to **GND**.  
- This allows detecting a button press as LOW.

---

## Step 3: Connect the Buzzer

| Buzzer Pin | Arduino Pin |
|------------|------------|
| Positive (+) | D10 |
| Negative (-) | GND |

---

## Step 4: Connect the LCD1602

| LCD Pin | Arduino Pin / Connection |
|---------|-------------------------|
| RS      | D12 |
| E       | D11 |
| D4      | D5  |
| D5      | D4  |
| D6      | D3  |
| D7      | D2  |
| VSS     | GND |
| VDD     | 5V |
| V0      | Middle pin of 10k potentiometer (contrast) |

**Potentiometer:**  
- One side → 5V  
- Other side → GND  
- Middle → V0 (LCD contrast)

---

## Step 5: Power and Ground

- Make sure all components share a **common GND** with the Arduino.  
- LCD VDD, Arduino 5V, and potentiometer 5V connect to **Arduino 5V**.  
- Double-check all connections to prevent shorts.

---

## Step 6: Verify Connections

- LEDs: Pins D6–D9  
- Buttons: Pins A0–A3  
- Buzzer: Pin D10  
- LCD: Pins D2–D5, D11–D12  
- Potentiometer: V0 for contrast  

> After wiring, power the Arduino and verify that LEDs, buttons, buzzer, and LCD respond correctly.

---

## Installation Guide

Follow these steps to set up and run the Arduino Memory Game.

---

### Step 1: Clone the Repository
```bash
git clone https://github.com/<yourusername>/Arduino-Memory-Game.git
cd Arduino-Memory-Game
---
```
### Step 2: Open in VS Code with PlatformIO

1. Make sure **VS Code** is installed.  
2. Install the **PlatformIO IDE extension**.  
3. Open the cloned project folder in VS Code.  
4. PlatformIO will automatically detect the Arduino framework.

---

### Step 3: Connect Your Arduino Mega
```
1. Connect your Arduino via USB.  
2. Verify the **COM port** in PlatformIO:  
   - Go to **PlatformIO → Devices** to check.  
3. Ensure the board type is set to whatever Arduino you are using in `platformio.ini`.

---
```
### Step 4: Build the Code

1. Click **PlatformIO: Build** (check mark icon).
2. The Required Lbrary fot the lcd screen can be downloaded here [LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c)
3. Move the header and cpp file into your lib folder in your PlatformIO project
4. PlatformIO will automatically fetch required libraries (e.g., `LiquidCrystal`).  
5. Confirm there are **no compilation errors** before uploading.

---

### Step 5: Upload the Code

1. Click **PlatformIO: Upload** (right arrow icon).  
2. The Arduino will reset, and the LCD should display:

## Video of Functioing Breadboard - Excuse the messy wires :)

[Watch Demo Video](https://drive.google.com/file/d/1xiahg6mQPKFb43g2Cn1vwePqr69rT-Jt/view?usp=sharing)

