# Team Implementation Report
 
Contents:
* [Overview]()
    - [Logic Diagram]()
    - [Pseudocode]() 
* [Technical Description]()
* [Hardware]()
	- [Libraries]()
	- [Schematic]()
	- [PCB]()
       
---

#### Overview   
[Greenhouse-Bot Master Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Code_Updates/Master_Code.c)   
* Greenhouse-Bot is an autonomous solution to ensuring optimal ambient temperatures and humidities are maintained inside commercial greenhouses.
* The design is adapted from a conventional RC car: featuring a rear drive motor and forward servo motor for independent velocity and steering adjustments, and an onboard Mbed LPC1768 Microcontroller for coordinating and executing programmable logic instructions.   
* When deployed: 
	- the car follows a pre-determined route marked on the floor with the aid of two [infrared sensors](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/IR_Sensor_Technical_Documentation.md). 
	- ambient temperatures and humidities are monitored using a [HTU21D Temperature and Humidity sensor](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/Temperature_and_Humidity_Sensor_Technical_Documentation.md). 
	- obstacle detection is faciliatated by an [ultrasonic](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/UltraSonic_Sensor_Technical_Documentation.md) sensor.
* In the event the Greenhouse-Bot detects temperatures or humidities outside optimal ranges, or encounters an obstacle, an alarm will be sounded.
 

#### Logic Diagram   
The below diagram illustrates the operational logical flow processes of the Greenhouse-Bot.   
   
<img src="Final_Report/Images/flow_chart.png" alt="Program flow chart." width="1200" height="1000">

#### Pseudocode  
The following pseudocode describes the operational logical processes of the Greenhouse-Bot.    
```
int main(){
	set car velocity;
	initialise ultrasonic sensor measuring;
	
	while (car is running){
		read IR sensor;
		adjust steering if car off course;
		
		read temperature and humidity sensor;
		while (ambient temperature or humidity is outside required ranges){
			stop the car;
			sound the alarm;
		}
		
		read ultrasonic sensor;
		while (distance to obstacle below threshold){
			stop the car;
			sound the alarm;
			check distance to obstacle;
}
```
---
# Technical Description



# Imported Libraries


### mbed head libary:

`#include "mbed.h"`

### Temperature and humidity sensor libary:

`#include "HTU21D.h"`

### Ultrasonic sensor libary:

`#include "ultrasonic.h"`


- **Temperature and humidity sensor technical documentation:**
- **IR sensor technical documentation:**
- **Ultrasonic sensor sensor technical documentation:**
- **Speaker technical documentation:**

# Known Issues
List any known issues (bugs) in your software, and describe workarounds if they exist.

The code cannot be tested due to current pandamic. Limited access to hardware. 

---

# Hardware

Due to the ongoing COVID-19 pandamic we werer unable to produce a hardware solution for our product. However to overcome this issue we have created a schematic using the EAGLE autocad software. The EAGLE software has allowed us to create a schematic and a PCB that can be used to create the actaul harware if the correct components are used.

## Libraries

To create the schematic we have had to use some 3rd party libraries.
Here are the libraries used and the components used from them.

* diy-modules.lbr:
	- Ultrasonic Ranging Moule HC-SR04
	- Digital Humidity & Temperature Sensor HTU21D
	

* MBED_v2.1.lbr:
	- mbed Microcontroller


* SparkFun-Sensors.lbr:
	- Reflective object sensor x2


* SparkFun-Connectors.lbr:
	- Power Jack

## Schematic
The figure below show the final Schematic design that we have created with all the components attached to the mbed board.
<img src="Final_Report/Images/PCB_design.png" width="100%" height="100%">

## PCB
The figure below shows the final PCB desgin. This has been autorouted with 2 layers. The top trace is in red and the bottom trace is on blue.
<img src="Final_Report/Images/PCB_printed_circuit_board.png" width="100%" height="100%">
