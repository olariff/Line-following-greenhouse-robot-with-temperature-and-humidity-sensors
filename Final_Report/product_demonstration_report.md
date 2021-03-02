# Product Demonstration Report

This documentation continues from the [MVP product demonstration](Final_Report/MVP/MVP Product Demonstration.md) technical documentation. The MVP product demonstration illustrates a inital design thoughts behind the temperature and humidity monitoring line follower. The documentation describes a outline of the project and highlights the groups inital thought process behined designing the line follower.  

---
 ## Introduction 

The project is a temperature and humidity monitoring line follower which, is set to follow a black line painted on the floor in a indoor strawberry farm and, constantly record temperature and humidity. The objective of the robot is to monitor temperature and humidity around the farm to avoide microclimate. It is important that the temperature and humidity is equally distributed throughout the greenhouse for optimal growth of crops. In a event the line follower detects abnormal temperature and humidity it will stop and sound the speaker. The robot will stop and sound the speaker, in instant it detects an object in front of it. It sounds the speaker to inform the workers to clear the path. 

## Design description
The design concept of the temperature and humidity monitoring line follower is infrared (IR) sensors are used to detect the black line on a white floor of the greenhouse. IR sensor measures infrared light radiated from a object in its field of view. The infrared light radiated from a black and white surface is different. When light is reflected on a white surface, most of the light is reflected back, while, a light reflected on a black surface is completely absorbed. This concept of reflected ligh is used to build the line follower. 



<img src="Final_Report/Images/IR_sensor.jpeg" alt="IR sensor illustration" width="450" height="650">


|  |  |
| ------ | ------ |
| <img src="Final_Report/Images/move_foward.jpeg" alt="Move forward" width="500" height="450"> | <img src="Final_Report/Images/turn_left.jpeg" alt="Turn left" width="500" height="450"> |
| <img src="Final_Report/Images/turn_right.jpeg" alt="Turn right" width="550" height="500"> | <img src="Final_Report/Images/ultrasonic_design.jpeg" alt="Turn right" width="600" height="450">|



## Implementation description



<p align="center">
    <img src="Final_Report/Images/circuit_design.jpg" alt="Basic outline of the circuit" width="1000" height="850">
</p>

Figure 1: The 
This section should contain a brief description and demo of product you have built.



Include screenshots (actual screenshots, not mock ups) of all of the facets of the product working.
Link consecutive screenshots together with a brief narrative explaining how the product works, e.g. a sentence "Click on OK and it takes you to the next window", "On starting the app, the following window is shown".  This document should not take you a long time to create - it's just pasting photos and adding explanatory sentences between them, so that your MVP is adequately described.
Make sure an image of each window of your software is included - so that a person who has not seen the actual demo of the product has a good idea of what your product currently does.
If your product is a physical device (a hardware product) then you may replace all of the above screenshots by actual photos/vidoes where you feel it is appropriate.
Make sure this section includes any functionality/features you are particularly proud of.
Indicate clearly which parts of the functionality shown in the screenshots are currently incomplete, and what is likely to change in the final version.  For example if a graph displayed is currently based on static hard-coded data for the MVP, but in the future version the graph will dynamically change depending on fresh data, then point this out explicitly.
