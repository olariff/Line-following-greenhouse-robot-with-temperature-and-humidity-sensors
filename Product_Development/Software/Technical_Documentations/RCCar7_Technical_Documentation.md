## RCCar7 - Technical Documentation    
---
##### [RCCar7 Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/RCCar07_Steering_and_Velocity_Unit_Code.c)
---
* RCCar7 implements control of the basic movements required by an autonomous vehicle; specifically its steering and linear velocity.    
* It requires the use of a microcontroller platform capable of providing PWM output to motors (here the Mbed LPC1768).    
* The code merely demonstrates its control capabilities and is intended to be adapted as required into programs of larger scope and complexity.
---
---
### _**Libraries**_

`#include "mbed.h"`
* The mbed library header file is required for PWM motor control via microcontroller pin I/O.
---
---
### _**PWM Pinouts**_   
(This PWM control uses the [Mbed PwmOut interface](https://os.mbed.com/handbook/PwmOut) which governs the frequency and mark-to-space ratio of digital output signals.)

`PwmOut steering(p21);`
* The PwmOut steering object facilitates PWM motor control via pin 21 to modify the angle of car's front non-drive wheels.
* It is achieved by setting the duty cycle of the output signal sent to the servo motor using the following PwmOut library functions:
    - `steering.period(0.02);` sets PWM output frequency at 50Hz (using a 20mS period) during program initialisation.
    - `steering.pulsewidth(s/2000+0.001);` adjusts PWM output mark-to-space ratio during program run time.

`PwmOut velocity(p22);`   
* The PwmOut velocity object facilitates PWM motor control via pin 22 to modify the rotational velocity of the car's rear drive wheels. 
* It is achieved by setting the duty cycle of the output signal sent to the drive motor using the following PwmOut library functions:
    - `velocity.period(0.02);` sets PWM output frequency at 50Hz (using a 20mS period) during program initialisation.
    - `velocity.pulsewidth(s/2000+0.001);` adjusts PWM output mark-to-space ratio during program run time.
---
---
### _**Functions**_   
`void Steering(float s)`
```
// Steering expects -1 (left) to +1 (right)
void Steering(float s) {
    s=s+1;
    if (s>=0 && s<=2) {
        steering.pulsewidth(s/2000+0.001);
    }
}
```
* This function controls the angle the front non-drive wheels.
* It expects a float value in the range of -1 to +1 which is used to modify servo position by updating the pulse width of the output signal sent from pin 21.

`void Velocity(float v)`
```
// Velocity expects -1 (reverse) to +1 (forward)
void Velocity(float v) {
    v=v+1;
    if (v>=0 && v<=2) {
        if (vo>=1 && v<1) {                 //
            velocity.pulsewidth(0.0014);    // this is required to
            wait(0.1);                      //
            velocity.pulsewidth(0.0015);    // move into reverse
            wait(0.1);                      //
        }                                   //
        velocity.pulsewidth(v/2000+0.001);
        vo=v;
    }
}

```
* This function controls the velocity of the rear drive wheels.
* It expects a float value in the range of -1 to +1 which is used to update the pulse width of the output signal sent to the motor from pin 22.


--- 


