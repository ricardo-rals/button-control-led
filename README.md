
# LED Control Project with Raspberry Pi Pico

This project demonstrates how to control three LEDs (green, red, and blue) using a Raspberry Pi Pico. The system is triggered by a button, which starts a sequence of LED activation with a 3-second delay between each state. The button can only be pressed again after the sequence is completed.

## Features
- The LED sequence starts when the button is pressed.
- The sequence follows the order:
  1. All LEDs turn on.
  2. After 3 seconds, two LEDs turn off.
  3. After another 3 seconds, only one LED remains on.
  4. After another 3 seconds, all LEDs turn off.
- The button is disabled until the sequence completes.
- A debounce mechanism prevents false button presses.

## Hardware Requirements
- Raspberry Pi Pico
- Three individual LEDs (Green, Red, Blue) connected to GPIOs
- One push button connected to GPIO 5
- Three 330 Ω resistors for LEDs
- Breadboard and jumper wires

## Software Requirements
- Raspberry Pi Pico SDK
- CMake
- GCC ARM Toolchain
- Visual Studio Code (optional, for development)

## Code Structure
```
project_root/
├── src/
│   ├── leds_control.c
│   ├── button_control.c
│
├── includes/
│   ├── leds_control.h
│   ├── button_control.h
├── button-control-led.c
└── CMakeLists.txt
```

## Setup and Simulation in Wokwi or Visual Studio Code
### Wokwi
1. Open [Wokwi](https://wokwi.com/) in your browser.
2. Create a new RP2040 project.
3. Upload the source files (`main.c`, `leds.c`, `button.c`, and headers) to the Wokwi environment.
4. Configure the circuit with LEDs and a button connected to appropriate GPIO pins.
5. Use the built-in serial monitor to observe the LED sequence.
6. Click "Start Simulation" to run the experiment.

### Visual Studio Code
1. Install the necessary extensions for Pico development.
2. Clone this repository and open it in VS Code.
3. Configure and build the project using CMake and the GCC ARM Toolchain.
4. Flash the compiled binary onto the RP2040 board.
5. Use a serial monitor in VS Code to observe the LED sequence.

## Running the Experiment
- Press the button to start the LED sequence.
- Observe the LEDs turn on and off in the defined pattern.
- The button will be disabled until the sequence completes.
- Monitor the serial output to track button presses and LED states.

