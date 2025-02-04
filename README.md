# LED Control Project with Raspberry Pi Pico  

This project demonstrates how to control three LEDs (green, red, and blue) using a Raspberry Pi Pico. The system is triggered by a button, which starts a sequence of LED activation with a 3-second delay between each state. The button can only be pressed again after the sequence is completed.  

## Required Components  

- Raspberry Pi Pico  
- 3 LEDs (green, red, and blue)  
- 3 resistors (330 Ω)  
- 1 push button  
- Jumpers and a breadboard  

## Wiring Diagram  

Connect the components as follows:  

- **LEDs**:  
  - Green LED: GPIO 13  
  - Red LED: GPIO 12  
  - Blue LED: GPIO 11  
  - The positive terminal (anode) of each LED should be connected to the corresponding GPIO.  
  - The negative terminal (cathode) of each LED should be connected to a 330 Ω resistor, which is then connected to GND.  

- **Button**:  
  - One terminal of the button is connected to GPIO 5.  
  - The other terminal of the button is connected to GND.  
  - Use an internal pull-up resistor on GPIO 5.  

## Source Code  

The source code is written in C and uses the Raspberry Pi Pico SDK. It can be found in the `main.c` file in this repository.  

### Code Features  

1. **LED Activation**:  
   - When the button is pressed, all three LEDs turn on.  
   - After 3 seconds, two LEDs turn off, leaving only one LED on.  
   - After another 3 seconds, only one LED remains on.  
   - After another 3 seconds, all LEDs turn off.  

2. **Button Debounce**:  
   - The code includes a simple debounce logic to avoid false button readings.  

3. **Activation Restriction**:  
   - The button can only be pressed again after the LED sequence is completed.  

## How to Compile and Upload the Code  

### Prerequisites  

- Visual Studio Code with the C/C++ extension.
- Raspberry Pi Pico SDK.
- CMake for building the project (if needed for other setups). 

### Compilation Steps  

1. Clone the project repository:  
   ```bash  
   https://github.com/ricardo-rals/button-control-led.git
   cd button-control-led 
   ```  

2. Open the project in Visual Studio Code.

3. Set up the Raspberry Pi Pico W SDK according to the [official documentation](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

4. Follow the instructions in Visual Studio Code to build and upload the project to your Raspberry Pi Pico.

## Testing the Project  

1. After uploading the code to the Pico, connect the components according to the wiring diagram.  

2. Press the button to start the LED sequence.  

3. Observe the following sequence:  
   - All LEDs turn on immediately after pressing the button.  
   - After 3 seconds, two LEDs turn off.  
   - After another 3 seconds, only one LED remains on.  
   - After another 3 seconds, all LEDs turn off.  

4. The button can only be pressed again after the sequence is completed.  


