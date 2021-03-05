## RCCar7 - Technical Documentation
---
* RCCar7 implements control of the basic movements required by an autonomous vehicle; specifically its steering and linear velocity.    
* It requires the use of a microcontroller platform capable of providing PWM output to motors (here the Mbed LPC1768).    
* The code merely demonstrates its control capabilities and is intended to be adapted as required into programs of larger scope and complexity.

---
_**Libraries**_

`#include "mbed.h"`
* The mbed library header file is required for PWM motor control via microcontroller pin I/O.

_**PWM Pinouts**_   
(This PWM control uses the Mbed PwmOut interface which governs the frequency and mark-to-space ratio of digital output signals. [^1]  )

`PwmOut steering(p21);`
* This object facilitates PWM motor control via pin 21 to modify the angle of car's front non-drive wheels.
* Output frequency is set at 50Hz (using a 20mS period) at program initialisation `steering.period(0.02);`
* Output mark-to-space ratio is s 

`PwmOut velocity(p22);`
* This object facilitates PWM motor control via pin 22 to modify the speed of the car's rear drive wheels.
* Output frequency is set at 50Hz (using a 20mS period) at program initialisation `velocity.period(0.02);`
* 

_**Functions**_

`void Steering(float s)`
* This function controls the angle the front non-drive wheels.
* It expects a float value in the range of -1 to +1 which is used to modify servo position by updating the pulse width of the output signal sent from pin 21.

`void Velocity(float v)`
* This function controls the velocity of the rear drive wheels.
* It expects a float value in the range of -1 to +1 which is used to update the pulse width of the output signal sent to the motor from pin 22.



[^1]: Mbed PwmOut Documentation: [https://os.mbed.com/handbook/PwmOut](https://os.mbed.com/handbook/PwmOut)

