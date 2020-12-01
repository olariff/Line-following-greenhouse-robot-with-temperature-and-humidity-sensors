# **Product Demonstration Report**

As a team we have agreed to design and develop a pathfinder bot to monitoring temperature and humidity in indoor greenhouse. With the on-going covid-19 restrictions we are not physically able to demonstrate our product. We cannot create quick turn-around solution to a problems and test to see if the solution words. This is in part due to the limited time available in the schedule of session. This will have a major affect of the development and testing of our code and product. It is important to highlight this in our [**risk log**](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/MVP/MVP%20Requirements%20and%20Risk%20Log.md).

## Introduction

This report will contain a brief description and demo of the product. The demo of the product will include implemention and testing codes and, key aspects of the product along its devlopment cycle. The product demonstration section will be recoard of the problems and solution we encountered while developing the pathfinder bot. The demonstration will include facets of a working product. 

## Inital design thoughts

### Project: Pathfinder for indoor green House (_for monitoring temperature and humidity in greenhouse_)

Some of the importance of managing temperature and humidity in a greenhouse are: 

-   Pests and disease control. 

        - Stressed crops are more expectable to pests and diseases. 
        - Mildew and mold can grow and spread quickly. 
        - Poorly controlled humidity can lead to perfect breeding ground for disease. 

-   Encourage crops performance for optimal growth. 

        - Steering the crops to grow to a particular growth cycle leads to high yield. 
        - Increase the ability of crops to take in extract nutrition for soli and environment leads to a tastier produce. 
        - Corps that require a particular environmental condition can grow. 
          Example: Iceland (due to icy cold environment and geo-thermal warm soil vegetables cannot be grown in outdoor farms). 

In a greenhouse the it is crucial to maintain a constant temperature and humidity. This is a tricky process as simply opening a door can create a micro climate. It is important that the temperature and humidity is equally distributed throughout the greenhouse to avoid microclimate. 

The main benefit of maintaining the temperature is a high yield of crops from a single plant. This increases the rate at which plants can grow and ensures that the plant keep producing goods until end of the growth cycle. In addition, with come crops the growth cycle can be increased or altered; where in some cases, ensuring that the plants keep producing good all year around. This helps the create a supply all year around for a highly desirable goods. 

The temperature and humidity go hand in hand as changing the temperature can change the humidity. There is no perfect temperature and humidity that fits all plants. It is important to find out the ideal temperature and humidity for a given crop. 

In an indoor greenhouse farms some of the methods used to control the temperature and humidity are fans, heaters, vents, shading cloth and fog machines. Our project proposal is a pathfinder bot that patrols around the greenhouse constantly monitoring temperature and humidity to ensure that there is no microclimate and the temperature is equally distributed around the greenhouse. The pathfinder will use sophisticated temperature and humidity sensor to record and compare with a reference values. If there is a huge temperature and humidity deviation the temperature, humidity location and time will be flagged. 


#### Case study: 
- A perfect case study are indoor greenhouses Iceland, where high in demand vegetables such as carrots, cucumbers, potatoes and cabbages are grown all year around in to meet the demand. These are just a few examples and in addition, the crops are grown using electricity and heat produced by the geothermal energy. 

- In the UK indoor farms are becoming a better model for growing plant based foods to change the eating habits. Indoor farming has been accelerated with the introduction of vertical farming where, crops are grown in a stacked system indoor under fully controlled conditions without the need for solar energy.

The case studies above are a great example of where are project is focused on. Growing crops indoor requires controlled conditions where temperature and humidity need to be controlled precisely for optimal growth. There is financial opportunities in a product which is able to control temperature and humidity. 


#### Application: 

The greenhouse crop we have decided to focuses on is strawberries as it is a high desired crop recognized for their juicy flavor, deep scarlet colour and nutritional benefits. Strawberries are true local summer fruit and require a string of cool temperature to flower and hot, humid temperature to develop and constate their sweetness. They are widely used in desserts and dried breakfast cereal. They are a perfect example of a crop which is grown all year around in indoor greenhouse to meet the demand. To increase their sweetness the daytime temperature needs to be 24 degrees Celsius  and the night temperature 13 degrees Celsius. Cool night temperature allows the fruit to develop their flavor and hot day time temperature concentrate the flavor. The humidity need to be 60% to 75%, as it benefits the nutrition of the fruit. Temperature and humidity is not the only factors which affects the growth of the fruit. Good quality soil is needed to increase its calcium uptake and sunlight is needed for photosynthesis to develop the deep scarlet colour. Temperature and humidity are importation to make sure that the crop can be grown all year around in an indoor green house. 

## Demonstration

As a group we thought about some of the components we may require to achieve a pathfinder project. We came up a list and a purpose of each component.  

The list of components to be used to devlope the pathfinder bot: 
- A line follower (to to detect the lines on the floor). 
- H-bridge (to drive the motors). 
- 2 motors (to drive the bot). 
- Temperature and humidity sensor (to recoard te and humidity). 
- Push button switch (to execute and pause the mbed program). 
- LCD diaplay (to display the current temperature and humidity recoarded by the sensor, and the coordinates of the robot). 

We used the component list we created a rough sketch of what out circuit might look like:

<p align="center">
  <img src="MVP/images/circuit_design.png" alt="Basic outline of the circuit" width="575" height="350">
</p>
Figure 1: Basic inital design of the circuit created in [Fritzing](https://fritzing.org) CAD software.      

Figure 1 shows a inital breadboard design of the components we place to use. The design takes in input from the three line followers which will be attached to the front of the cars chassis facing the floor in a row configuration. A line follower is a infrared black and white colour sensor which, measures the amount of infrared light reflecting back from a surface. There is a less light reflecting from a black surface and a white one. If all the line followers read a black colour on the floor send control command to the H-bridge to move the motors accordingly. The temperature and humidity sensor in the middle of the board writes to the analogue inputs on the mbed microcontroller. This data is compared with the reference temperature and humidity. 