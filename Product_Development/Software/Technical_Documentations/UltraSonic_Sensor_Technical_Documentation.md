# Ultrasonic Sensor Technical Documentation
- This sensor is used to detect whether there is an object or any obstacle on the path the car is is following.
- The implementation of this sensor in the master code is to detect if there is an object in front of the car at a distance less than 0.5 meter.
- In case there is an object within 0.5 meter in front of the car, the car will stop immediately and will turn on the speaker to indicate to the existance of an obstacle in front of it.
- Once the object/obstacle is reomoved from the path the car is taking, the car will turn off the speaker and carry on moving on its path.

Click [here](Product_Development/Software/Component_Unit_Test/ultrasonic_sensor_unit_code.c) to view the unit test code of the Ultrasonic Sensor
---

## Libraries
`#include "mbed.h"` 
- This is the mbed library header

`#include "ultrasonic.h"`
- This is the ultrasonic Sensor header

## AnalougeIn Pinouts
`ultrasonic mu(p7, p8, .1, 1, &Detecting_Objects)`
- This line of code create an object of the ultrasonic sensor which is called mu. 
- This object will be updated every 0.1 seconds and it will timeout after 1 second. 
- This object will call the Detecting_Objects function every time there is a change in the distance.

|The ultrasonic pin name| The corrosponding Mbed pin number|
|-|-|
|Trigger (This pin is acting as a clock)|p7|
|Echo (This pin is acting as the data channel)| p8|

## Functions
`mu.startUpdates()`
- Running this funtion at the beginning of the main function will initiate measuring the distance to the closest object in front of the car.

`void Detecting_Objects(float distance)
{
    Dis = distance;
}
`
- When this function is called, it saves the distance between the sensor and the closest object to it in the Dis variable.
- This function is called every time the distance has changed by the `mu.checkDistance()` funtion.

`mu.checkDistance()`
- This function is called in each iteration of the main While loop.
- It keeps checking weather the distance to the closest object has changed or not.
- It calls the `Detecting_Objects` funtion when the distance has changed.
- It passes the distance variable to the `Detecting_Objects` funtion. 

## Acknowledgment
This is the [origial code](https://os.mbed.com/users/ejteb/code/Nucleo_UltrasonicHelloWorld//file/4a5586eb1765/main.cpp/).  
