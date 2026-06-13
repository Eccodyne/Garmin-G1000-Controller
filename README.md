## 📌 Welcome to the "Garmin G1000 Controller" Project!
![Garmin G1000 Controller](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/GarminG1000Controller.JPG)

# Garmin-G1000-Controller
This a physical controller for the main navigation functions of the Garmin G1000, to be used with Microsoft Flight Simulator 2024.

### 💡What is this repository for?
This repository contains the code and build instructions for my Garmin G1000 Controller Project with the required 3D printing files to be found at Makerworld.com. You can build your own device to control the main navigation controls of the Garmin G1000 in Mircosoft Flight Simulator 2024 with just a few electronic parts, a 3D printed housing and a little bit of Arduino code.

This project is not complicated and does not require a high level of technical know-how. You just need time, patience and to follow the instructions as set out below.

Link to 3D printing files on Makerworld: [Click](https://makerworld.com/de/models/2291219-air-quality-monitor-esp32#profileId-2500035)

---
### 🛒 What components do I need to make this project?
- 3D printed housing parts
- Arduino 2560 MEGA compatible board with USB-B port (not USB-C!)
- 4x KY-040 360 degree rotary encoders (see important note/image below)
- 1x KY-023 Joystick module
- 18x tactile 2-pin buttons
- Mini Breadboard, but only the GND/VOLTAGE part is required (you can detach this part from the other parts of the breadboard, see image below)
- Jumper wires
- 12x M2.5 screws to attach the Arduino 2560 MEGA board and the rotary encoders to the housing
- 8x M3 screws to attach the top plate and the joystick to the housing
- USB-B cable to connect the controller to your PC
- 4x self-adhesive rubber feet to be attached to the bottom of the housing

***
### 💾 What software do I need to make this project?  
- Arduino IDE (free of cost)
- Mobiflight (free of cost, consider donating for this great project!)

***
### 🔎 How do I get started?
- Download *.3mf or *.stl files from the Garmin G1000 Controller Project on Makerworld: [Click](https://makerworld.com/de/models/2291219-air-quality-monitor-esp32#profileId-2500035)
- Print the files with your 3D printer. The buttons MUST be printed with a 0.2mm nozzle, a 0.4mm nozzle will not work! 
- Install the Arduino 2560 MEGA board to the housing using the M2.5 screws. Do not use force.
- Attach the tactile buttons to the button covers 
- Install the joystick to the cover plate using M3 screws
- Install the rotary encoders to the cover plate using M2.5 screws
- Attach jumper wires to the tactiles buttons, 1x GND, 1X digital signal for each button (see images and instructions below). Connect the joystick and the rotary eoncoders with jumper wires in accordance with the instructions coming with for parts. You can also look up pin layouts via a Google search.
- Attach the GND/VOLTAGE part of breadbord to one of the buttons covers (see image below)
- Connect all GND pins of the components to the GND/Voltage breadboard. For the tactile buttons, it does not matter which of the two pins you choose.
- Connect all VOLT pins of the joystick and the rotary encoders to the GND/Voltage breadbord
- Connect the VRX pin of the joystick to pin A0 of the Arduino 2560 MEGA board and the VRY pin to A1 of the Arduino 2560 MEGA Board
- Connect a 3V and GND jumper wire between the GND/Voltage breadboard and the Arduino 2560 MEGA board 
- Place heatshrink tubes between the pins of the tacticle buttons to avoid shorts / false signals
- Important: Only the VRX and VRY pins of the joystick need to be connected to the A0 / A1 pins of the Arduino MEGA 2560. All other signal pins need to be attached to the digital pins of the Arduino 2560 MEGA.
- Important: It does not matter to what digital pins you connect the jumper wires to, the Arduino sketch / code will tell you the pin numbers you need to write down (see instructions below)
- Leave the housing open for now


***
### 💡 Installing required Arduino libraries
You will need to install the following libraries for this project to work:
- TFT_eSPI Library
- BME680 libraries for Bosch sensor
- Adafruit BME680 Library

***
### 📄 Adjusting the code for this project
- Open Arduino IDE
- Create a new sketch (= new project)
- Copy the code from this repository to the sketch
- If you want the temperature to be displayed in Fahrenheit and not Celcius, change line 29 as follows:
