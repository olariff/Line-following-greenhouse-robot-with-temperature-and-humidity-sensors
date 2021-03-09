# IR Sensor Technical Documentation
---

<img src="Final_Report/Images/IR_sensor_component.jpeg" alt="IR sensor component image" width="600" height="450">

Figure 1: IR sensor component image. 

<img src="Final_Report/Images/IR_sensor.jpeg" alt="IR sensor illustration." width="450" height="650">

Figure 2: IR sensor illustration. 

- Light is reflected from white surface and black surace absorbes light. 
- The line follower uses a IR sensor with a transmitter (Tx) and a receiver (Rx) (the receiver (Rx) is a photodiode).
- When the IR LED shines onto a white surface, light is reflects back which, generates a HIGH voltage in the receiver (Rx). 
- If the IR light is shining onto a black surface, light is absorbed which, generates a LOW voltage in the receiver (Rx).

Click [here](Product_Development/Software/Component_Unit_Test/IR_sensors_unit_code.c) for unit test code for the IR sensor

---
---

### _Libraries_

`#include "mbed.h"`

- The mbed library header file is required for analouge communicate with the mbed microcontroller pin I/O.

---
---

### _AnalougeIn Pinouts_
- The left and right IR sensors require analouge input pins in the mbed boad for communicate. 
- When the voltage at left IR sensor is LOW the line follower turns left. 
- When the voltage at right IR sensor is LOW the line follower turs right. 
- The left IR sensor OUT pin is connection to pin 15 (```AnalougeIn(p15)```). 
- The right IR sensor OUT pin is connection to pin 16 (```AnalougeIn(p15)```). 
- The information from the IR sensor is a voltage output.

Table 1: Left IR sensor pin connection table. 
| Left IR sensor pin name | mbed pin |
| ------ | ------ |
| 5V | Vout |
| GND (Ground) | GND |
| OUT | p15 |

Table 2: Rignt IR sensor pin connection table. 
| Left IR sensor pin name | mbed pin |
| ------ | ------ |
| 5V | Vout |
| GND (Ground) | GND |
| OUT | p16 |

### _Functions_

```left_sensor.mode(PullNone);```
```right_sensor.mode(PullNone);```

The ```.mode(PullNone)``` 



```left_sensor.read()```
```right_sensor.read()```

---
---
> ### _Acknowledgement_
> 
> The 
> 
> https://os.mbed.com/questions/69023/coding-for-ir-sensor/

