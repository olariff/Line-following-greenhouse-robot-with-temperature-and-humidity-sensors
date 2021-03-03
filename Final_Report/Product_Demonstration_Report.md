# Product Demonstration Report

This documentation continues from the [MVP product demonstration](Final_Report/MVP/MVP%20Product%20Demonstration.md) technical documentation. The MVP product demonstration illustrates a inital design thoughts behind the temperature and humidity monitoring line follower. The documentation describes a outline of the project and highlights the groups inital thought process behined designing the line follower.  

 ## Introduction 

The project is a temperature and humidity monitoring line follower which, is set to follow a black line painted on the floor in a indoor strawberry farm and, constantly record temperature and humidity. The objective of the robot is to monitor temperature and humidity around the farm to avoide microclimate. It is important that the temperature and humidity is equally distributed throughout the greenhouse for optimal growth of crops. In a event the line follower detects abnormal temperature and humidity it will stop and sound the speaker. The robot will stop and sound the speaker, in instant it detects an object in front of it. It sounds the speaker to inform the workers to clear the path. 

## Product Description
The design concept of the temperature and humidity monitoring line follower is infrared (IR) sensors are used to detect the black line on a white floor of the greenhouse. IR sensor measures infrared light radiated from a object in its field of view. The infrared light radiated from a black and white surface is different. When light is reflected on a white surface, most of the light is reflected back, while, a light reflected on a black surface is completely absorbed. This concept of reflected ligh is used to build the line follower. 

<img src="Final_Report/Images/IR_sensor.jpeg" alt="IR sensor illustration" width="450" height="650">

Figure 1: Light is reflected from white surface and black surace absorbes light.  


The line follower uses a IR sensor with a transmitter (Tx) and a receiver (Rx) (the receiver (Rx) is a [photodiode](https://www.electronicshub.org/photodiode-working-characteristics-applications/)). The transmitter (Tx) shines infrared light onto a surface and the receiver (Rx) recoard the infrared light reflected back. When the infrared light shines onto a white surface, most of the light reflects back generated high voltage in the receiver (Rx). When the infrared light shines onto a black surface, most of the light is absorbed which, generated low voltage in the receiver (Rx). In case, the voltage at the input is above a threshold voltage, this will indicate a white surface in field of view and will be interpreted as logic 1. If the voltage is below a threshold voltage this will indicate a black surface in field of view and will be interpreted as logic 0. This concept is used as the bases of allowing the line follower robot to detect the black line on the floor of the greenhouse. 

|  |  |
| ------ | ------ |
| <img src="Final_Report/Images/move_foward.jpeg" alt="Move forward" width="500" height="450"> | <img src="Final_Report/Images/turn_left.jpeg" alt="Turn left" width="500" height="450"> |
| Figure 2: Line follower moves foward if both IR sensors (left IR sensor and right IR sensor) are on white surface. | Figure 3: Line follower turns left if left IR sensor on black line and right sensor on white surface. |
| <img src="Final_Report/Images/turn_right.jpeg" alt="Turn right" width="550" height="500">  | <img src="Final_Report/Images/ultrasonic_design.jpeg" alt="Turn right" width="600" height="450">  |
| Figure 4: Line follower turns right if the right IR sensor no black line and left IR sensor on white surface. | Figure 5: Line follower stops and sounds the speaker of its path is obstrusted. |

The robot uses two IR light sensor to steer (left IR sensor and right IR sensor). When the left and the right IR sensors are both on white surfaces the input voltage from the sensord is above the threshold, the robot moves foward in a stright line. If the output voltage left IR sensor is below the threshold voltage and the voltage from the right IR sensor is above the threshold voltage, the robot turns left to keep in track with the black line. In a instant, the output voltage from the right IR sensor is below the threshold voltage and the output from the left sensor is above the threshold voltage the robot turns right. (Note: The IR sensor on a black surface/line will produce a lower voltage than the threshold voltage. IR sensor on a white surface will produce a higher voltage than the threshold voltage). IR sensors was a used to steer the car as the alternative option to steer the are was to use multiple cameras to keep the robot in track (on the black line). The concept of using the cameras was incomprehendible as it would require image processing to steer the car. Teaching the robot to preform image processing to find the black line is complicated, thus, increase the complexity of the program. With no prior knowledge of image processing from any of the group members, using photodiode was the best solution for this project. 

The line follower use a ultrasonic sensor to detect obstacles in front of it. If it's path is blocked, the robot stops and sounds a alarm using the speaker. The ultrasonic sensor measures the distance by using ultrasonic waves. The sensor emites an ultrasonic wave and measures the time it takes to receive the reflected waves. The ultrasonic sensor measures the distance of the object in front of it's field of view. The temperature and humidity sensor is attahced to robot and it constantly recoard the temperature and humidity. If the tempreature and humidity is not of range the line follower stops and sounds an alram using the speaker. This will informa the workers the temperature and humidity at it's current position is out of range to reference values. (Note: The reasearch carried out in the MVP product demonstration highlights that the temperature for optimal strawberry growth must be between 15 Celsius and 30 Celsius. The humidity of the greenhouse must be between 60% and 75%.)

<img src="Final_Report/Images/flow_chart.png" alt="Flow chart" width="1200" height="1000">

Figure 6: The flow chart show the basics working of the temperature and humidity line follower robot. 

The robot starts by entering a open WHILE loop (infinite loop). The temperature and humidity sensor is used to recoard temperature and humidity, this is compared with the reference temperature and humidity. If the temperature and humidity is below or over the reference values the robot stops and sounds the alarm. Else, the robot checks the ultrasonic sensor to determine if anything is front of it. If an object is in front of the robot, it will stop and sound an alarm, else, it will continue on to check the left IR sensor. In a event the left IR sensor is LOW/logic 0, this means the black line is in front of it's field of view. In this case the robot turns left, until the right IR sensor is LOW/logic 0. This means the black line is in front of the field of view of the right IR sensor and at this point the robot turns right. While the left and right IR sensor is HIGH/logic 1, this indicates that the field of view of both the sensors is white and this means that the robot is on a white surface with the black line in the middle. At this instant, the robot moves foward and the program returns back to the top of the infinite WHILE loop. 

<img src="Final_Report/Images/circuit_design.jpg" alt="Basic outline of the circuit" width="1000" height="850">


Figure 1: The 
This section should contain a brief description and demo of product you have built.








Include screenshots (actual screenshots, not mock ups) of all of the facets of the product working.
Link consecutive screenshots together with a brief narrative explaining how the product works, e.g. a sentence "Click on OK and it takes you to the next window", "On starting the app, the following window is shown".  This document should not take you a long time to create - it's just pasting photos and adding explanatory sentences between them, so that your MVP is adequately described.
Make sure an image of each window of your software is included - so that a person who has not seen the actual demo of the product has a good idea of what your product currently does.
If your product is a physical device (a hardware product) then you may replace all of the above screenshots by actual photos/vidoes where you feel it is appropriate.
Make sure this section includes any functionality/features you are particularly proud of.
Indicate clearly which parts of the functionality shown in the screenshots are currently incomplete, and what is likely to change in the final version.  For example if a graph displayed is currently based on static hard-coded data for the MVP, but in the future version the graph will dynamically change depending on fresh data, then point this out explicitly.
