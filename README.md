# Automatic Fish Feeder

The **Automatic Fish Feeder** is a 3D-printed device that automates feeding for aquarium fish. This feeder dispenses precise portions of food at set intervals, or on-demand via the Blynk app. Ideal for ensuring your fish are fed consistently, it includes customizable scheduling and manual feeding options for added flexibility. 

## Project Overview

This feeder is controlled by a NodeMCU and includes two servo motors: 
- **Servo 1** opens and closes a trap door to protect food from moisture.
- **Servo 2** rotates to dispense food portions as scheduled.

Using the Blynk app, you can set the number of portions to be dispensed at each feeding, initiate manual feedings, and automate feeding schedules remotely.

## Features

- **Remote Feeding Control**: Feed your fish anytime, anywhere with the Blynk app.
- **Customizable Portions**: Set the number of food portions per feeding with a Blynk slider.
- **Automated Feeding**: Schedule feedings by setting automation on the virtual pin (V3) for daily or weekly routines.
- **Moisture Protection**: A trap door, controlled by Servo 1, prevents moisture from entering the food tunnel.
  
## Components

- **3D-Printed Feeder Body**: Holds the food reservoir and dispensing mechanism. Securely assembled with screws.
- **Rotating Cylinder**: Ensures precise portioning of food by rotating to dispense a single serving each time.
- **NodeMCU (ESP8266)**: Manages the feeding schedule, portion control, and remote operations via Blynk.
- **Servo Motors**: 
  - **Servo 1**: Controls a trap door to prevent moisture from reaching the food.
  - **Servo 2**: Rotates the cylinder to dispense food portions.
  
### Printed Parts

The feeder body and assembly parts can be 3D-printed, with files available on my [Thingiverse page](https://www.thingiverse.com/thing:6806793).

## How It Works

1. **Food Portion Control**:
   - When initiated, the rotating cylinder fills with food, rotates to drop the food, and returns to its starting position.
   - The trap door opens only during the feeding, keeping the food dry and secure at all other times.
   
2. **Blynk Controls**:
   - **Button (V1)**: Manually feed a single portion.
   - **Slider (V2)**: Select the number of portions to dispense per feeding.
   - **Automation (V3)**: The automation feature in Blynk triggers the feeding sequence using the selected portion count.
   
3. **Automatic and On-Demand Feeding**:
   - The feeder can be set up to dispense food automatically using the Blynk automation feature, or manually with a button press.

## Code and Setup

1. **Libraries Required**: 
   - Blynk for ESP8266
   - Servo library for motor control

2. **Connections**:
   - Servo 1 connected to `D1` controls the trap door.
   - Servo 2 connected to `D2` manages the rotating cylinder.

3. **Code**:
   - All necessary code, wiring diagrams, and setup instructions are available in this repository.
   - Modify Wi-Fi credentials and Blynk authentication token as needed in `setup()`.

## Getting Started

1. **Print the Components**: Download and print parts from [Thingiverse](https://www.thingiverse.com/thing:6806793).
2. **Assemble the Feeder**: Attach the servos and assemble using screws.
3. **Upload the Code**: Upload the provided code to your NodeMCU.
4. **Set Up Blynk App**: Add a button on V1, a slider on V2, and set up an automation on V3 for scheduling.

## Conclusion

This project brings reliability and convenience to aquarium care, ensuring your fish are fed regularly and on time. With customizable feeding options and moisture protection, the **Automatic Fish Feeder** is an ideal solution for fish enthusiasts, providing peace of mind even when you're away from home.

---

Check the repository for detailed assembly instructions and wiring diagrams. Let me know if you make any improvements or have suggestions!
