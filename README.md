## 📌 Welcome to the "Garmin G1000 Controller" Project!
![Garmin G1000 Controller](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/GarminG1000Controller.JPG)

# Garmin-G1000-Controller
This a physical controller for the main navigation functions of the Garmin G1000, to be used with Microsoft Flight Simulator 2024.

### 💡What is this repository for?
This repository contains the code and build instructions for my Air Quality Monitor Project with its 3D printing files to be found at Makerworld.com. You can build your own device to control air quality with just a few electronic parts, a 3D printed housing and a little bit of Arduino code.

The monitor displays temperature, humidity and air pressure - all values are refreshed in 2s intervalls. There is also an air quality indicator at the bottom of the screen which tells you if air quality is good or poor.

Link to 3D printing files on Makerworld: [Click](https://makerworld.com/de/models/2291219-air-quality-monitor-esp32#profileId-2500035)



---
### 🛒 What components do I need to make this project?
- 3D printed housing parts
- Arduino 2560 MEGA compatible board with USB-B port (not USB-C!)
- 4x KY-040 360 degree rotary encoders (see important note/image below)
- 1x KY-023 Joystick module
- 18x tactile 2-pin buttons
- Mini Breadboard, only the GND/VOLTAGE part (you can de-attach it from the other parts of the breadboard)
- Jumper wires
- 12x M2.5 screws to attach the Arduino 2560 MEGA board and the rotary encoders to the housing
- 8x M3 screws to attach the top plate and the joystick to the housing
- USB-B cable to connect the controller to your PC

***
### 💾 What software do I need to make this project?  
- Arduino IDE
- Mobiflight

***
### 🔎 How do I get started?
- Download *.3mf or *.stl files from the Air Quality Monitor Project on Makerworld: [Click](https://makerworld.com/de/models/2291219-air-quality-monitor-esp32#profileId-2500035)
- Print the files with your 3D printer ("Front" and "Back" part)
- Install the angled USB-C adapter to the ESP32-2432S028R in case you are not using an angled USB-C cable
- Install the ESP32-2432S028R to the housing using the M3 screws. Do not use force.
- Install the sensor to the housing using the M2 screws. Do not use force.
- Connect the data cable to the ESP32-2432S028R and the sensor. You want to use the expansion port "IC2" which is located next to the card reader. This port provides for pin 22 (used for SCL signal) and pin 27 (used for SDA signal). See image below for details.
- Important: Make sure that the SDA pin of the sensor is connected to the SDA pin of the ESP32-2432S028R. The same goes for the SCL pin. If wiring is not correct, you will get an error message on the display.
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
