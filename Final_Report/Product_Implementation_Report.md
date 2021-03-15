# Team Implementation Report
 
Contents:
* [Overview]()
    - [Logic Diagram]()
    - [Pseudocode]() 
* [Technical Description]()
       
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
This section should describe the software implementation in prose form. 
Focus on how the code was designed and built.
It should make a clear description that could be used by any future developers to maintain and extend your code, if necessary.
Describe important functions / classes / class hierarchies.
In this section, you should also wish to highlight any technical achievements your team is particularly proud of, including relevant code snippets.



# Algorithms and Data Structures
Describe datastructures of at least one component of your implementation.
Describe at least one algorithm used in your implementation.
In both cases, describe the space / time complexity of each.

# Imported Libraries
List any 3rd party libraries that were used and describe what functionality they provided.

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
