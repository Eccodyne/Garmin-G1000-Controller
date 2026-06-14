## 📌 Welcome to the "Garmin G1000 Controller" Project!
![Garmin G1000 Controller](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/GarminG1000Controller.JPG)

# Garmin-G1000-Controller
This a physical controller for the main navigation functions of the Garmin G1000, to be used with Microsoft Flight Simulator 2024.

### 💡What is this repository for?
This repository contains the code and build instructions for my Garmin G1000 Controller Project with the required 3D printing files to be found at Makerworld.com. You can build your own device to control the main navigation functions of the Garmin G1000 in Mircosoft Flight Simulator 2024 with just a few electronic parts, a 3D printed housing and a little bit of Arduino code.

This project is not complicated and does not require a high level of technical know-how. You just need time, patience and to follow the instructions as set out below.

I have tested this controler in depth and it works perfectly!

Link to 3D printing files on Makerworld: [Click](https://makerworld.com/de/models/2927499-garmin-g1000-controller-ms-flight-simulator-2024#profileId-3276793)

---
### 🛒 What components do I need to make this project?
- 3D printed housing parts
- Arduino 2560 MEGA compatible board with USB-B port (not USB-C!)
- 4x KY-040 360 degree rotary encoders (see important note/image below)
- 1x KY-023 Joystick module
- 18x tactile 2-pin buttons
- Mini Breadboard, but only the GND/VOLTAGE part is required (you can detach this part from the other parts of the breadboard, see image below)
- Sufficient number of jumper wires
- 12x M2.5 screws to attach the Arduino 2560 MEGA board and the rotary encoders to the housing
- 8x M3 screws to attach the top cover and the joystick to the housing
- USB-B cable to connect the controller to your PC (this should come with the Arduino 2560 MEGA board, but you may want to purchase a longer cable)
- 4x self-adhesive rubber feet to be attached to the bottom of the housing

***
### 💾 What software do I need to make this project?  
- Arduino IDE (free of cost)
- MobiFlight (free of cost, consider donating for this great project!) [Link](https://mobiflight.com/)

***
### 🔎 How do I get started?
- Download *.3mf files for the Garmin G1000 Controller Project on Makerworld: [Link](https://makerworld.com/de/models/2927499-garmin-g1000-controller-ms-flight-simulator-2024#profileId-3276793)
- Print the files with your 3D printer. The buttons MUST be printed with a 0.2mm nozzle, a 0.4mm nozzle will not work! Use the printer settings in my 3mf files or apply them accordingly to your slicer should you not be using the BambuLab Studio slicer.
- Install the Arduino 2560 MEGA board to the housing using the M2.5 screws. Do not use force.
- Attach the tactile buttons to the button covers (see image below)
- Install the joystick to the cover plate using M3 screws
- Install the rotary encoders to the cover plate using M2.5 screws
- Attach jumper wires to the tactiles buttons, 1x GND, 1X digital signal for each button, what pin you choose for GND or VOLTAGE does not not matter (see images and instructions below).
- Connect one pin of the tactile buttons to a GND port on the breadboard and the other pin to a digital port of the Arduino 2560 MEGA. As noted above, for the tactile buttons, it does not matter which of the two pins you choose for GND or the digital signal.
- Connect the joystick and the rotary encoders with jumper wires in accordance with the instructions coming with for parts. You can also look up pin layouts via a Google search
- Fix the GND/VOLTAGE breadboard on top of one of the button covers (see image below). You can use self-adhevise tape, my breadbord already had self-adhesive tape applied to it
- Connect all GND/VOLT pins of the joystick and the rotary encoders to GND/Voltage pins of the breadbord, and all other digital pins of the joystick to the Arduino 2560 MEGA
- Connect the VRX pin of the joystick to pin A0 of the Arduino 2560 MEGA board and the VRY pin to A1 of the Arduino 2560 MEGA Board
- Connect a 3V and GND jumper wire between the GND/Voltage breadboard and the Arduino 2560 MEGA board 
- Place heatshrink tubes between the pins of the tacticle buttons to avoid shorts / false signals (see image below)
- Important: Only the VRX and VRY pins of the joystick need to be connected to the analogue A0 / A1 pins of the Arduino MEGA 2560. All other signal pins need to be attached to the digital pins of the Arduino 2560 MEGA
- Important: It does not matter to what digital pins you connect the jumper wires to, the Arduino sketch / code will tell you the pin numbers you need to write down (see instructions below)
- Leave the housing open for now

***
### 💡 Identifying the ports on your Arduino 2560 MEGA board
You will need to identify to which digital ports you have connected the tactile buttons and the rotary encoders to your Arduino 2560 MEGA board (VRX and VRY pins of the joystick need to be  connected to analogue pins A0 and A1, so you do not have to bother about these pins):
- Attach the wired Garmin G1000 controller to your PC with a USB-B cable
- Install and run the Arduino IDE
- Upload the "Portscanne.ino" sketch/code provided in the files section for this Github project to your Arduino 2560 MEGA board
- Open EXCEL and create a new file or use pen and paper
- Go back to Arduino IDE with the code running, open the log screen
- Write down each pin number that is displayed for each tacticle button when pressed. Note both the name of the button and the pin number - you will need this for MobiFlight adjustments later. The rotary encoders will provide two PIN numbers, one for a left turn and another one for a right turn. Take note of these. Also, press the rotary encoders down and note the pin number of the relevantr rotary encoder buttons
- Important: If one of the buttons or one of the rotary encoders does not show a pin/signal, the wiring may be bad/loose, so check if the jumper wires are connected properly to the pins
- Quit Arduino IDE
- Start MobiFlight andl flash the board with the Mobiflight firmware
- In MobiFlight, Import the" Garmin G1000 Controller.mfmc" and "Garmin G1000 Controller.mfproj" files provided for in the files section for this Github project
- Open the configuration for the modules in MobiFlight. You will need to change the pin settings for each tactile button and the rotary eoncoders in accorance with the notes you have taken above. If one of the your ports is blocked in Mobiflight, just move it to another unused pin  to make it available. This may take couple of minutes until you have set everything, but is easy to do.
- Once all is correctly configured and working, attach the top cover to the housing and attach the knobs to the rotary encoders - there are notches in the printed knobs, so you need to make sure that these notches are aligned with the nothes of the rotary encoders

***
### 💡 Control hints:

- Push the joystick button to activate map panning, press again to de-activate. Use the joystick to pan the map.
- Use the RANGE knob to zoom in and out of the map
- The faster you rotate the HDG and ALT knob, the higher the effect will be on the settings (ALT knob slow turn = 100 feet, ALT knob fast turn = 1,000 feet // faster turns on the HDG knob will cause higher changes).
- Press the HDG knob button to align heading with actual heading of the plane
- The FMS knob controls the LOWER FNS knob in the flight simulator. If you want to control the UPPER FMS knob, keep the RANGE knob button pressed and turn the FMS knob 

***
### 🛠 Assembly images

- Rotary encoders:

  IMPORTANT: Make sure to buy 4 encoders as shown on the right side of the image. The screw hole to the right is closer to the pins, this is what you need to buy. Do NOT buy the type of encoder shown on the left side of the image!

  ![Breadboard](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Encoder.JPG)

  
- Tactile buttons & pins:

Attach the tactile buttons to the button covers as follows. You can either solder the jumper cables to the pins, or remove the black plastic cover from a female pin, slide the connector over the pin and use a pliers to tighten the connector to the pin:

Buttons:

![Tacttile Buttons](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Buttons1.JPG)
![Tacttile Buttons](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Buttons2.JPG)

Pins:

![Tacttile Buttons](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Pin1.JPG)
![Tacttile Buttons](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Pin2.JPG)
![Tacttile Buttons](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Pin3.JPG)
![Tacttile Buttons](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Pin4.JPG)

- Breadboard GND & VOLTAGE:

You will only need the right part on this image:

![Breadboard](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Breadboard.JPG)

- Shrinking tubes to avoid shorts / false signals
  
![Breadboard](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/Tubes.JPG)

- MobiFlight settings page where you need to adjust your pin settings for each device
  
![Breadboard](https://github.com/Eccodyne/Garmin-G1000-Controller/blob/main/images/MobiflightSettings.jpg)

