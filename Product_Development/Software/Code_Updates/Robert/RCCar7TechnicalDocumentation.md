
### RCCar7 - Technical Documentation
---
	Overview
RCCar7 implements basic movement control for the autonomous vehicle; specifically steering and velocity. It requires the use of a microcontroller platform capable of PWM outputs (here the Mbed 1768), while its functionality is intended to be adapted as needed into more complex master programs for more specific purposes.

	Details
**Additional Libraries**

`#include "mbed.h"`
* The mbed library header file is required for PWM motor control via microcontroller pin I/O.

**PWM Pinouts** 
(This PWM control uses the Mbed PwmOut interface which governs the frequency and mark-to-space ratio of digital output signals. [^1]  )

`PwmOut steering(p21);`
* This object facilitates PWM motor control via pin 21 to modify the angle of car's front non-drive wheels.
* Output frequency is set at 50Hz (using a 20mS period) at program initialisation `steering.period(0.02);`
* Output mark-to-space ratio is s 

`PwmOut velocity(p22);`
* This object facilitates PWM motor control via pin 22 to modify the speed of the car's rear drive wheels.
* Output frequency is set at 50Hz (using a 20mS period) at program initialisation `velocity.period(0.02);`
* 



[^1]: Mbed PwmOut Documentation: [https://os.mbed.com/handbook/PwmOut](https://os.mbed.com/handbook/PwmOut)




 

	

