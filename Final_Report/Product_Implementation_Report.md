# Team Implementation Report
 
Contents:
* [Overview]()
    - [Logic Diagram]()
    - [Pseudocode]() 
* [Technical Description]()
       
---

#### Overview
[Greenhouse-Bot Master Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Code_Updates/Master_Code.c)   
* Greenhouse-Bot is an autonomous car designed to follow a pre-determined route and continually monitor temperatures and humidities inside commercial greenhouses to ensure optimal ambient conditions are maintained.
* The car features a rear drive motor capable of moving the 
* Infrared sensing is used to detect deviations from its intended course.
* Ultrasonic sensing 

	- The product is built on the Mbed LPC1768 Microcontroller platform, which coordinates sensor data  

#### Logic Diagram

<img src="Final_Report/Images/flow_chart.png" alt="Program flow chart." width="1200" height="1000">

#### Pseudocode   
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
