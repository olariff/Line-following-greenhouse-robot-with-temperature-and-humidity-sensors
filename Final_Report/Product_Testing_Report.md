# Product Test Report   
The following report details the various tests used to assess the autonomous car's performance.    
(Note: With lockdown restrictions imposed due to Covid-19, many tests were not possible to conduct physically - in this situation the team has used simulations where possible or continued with assumed ideal test results).   



---
### Part 1: Unit Testing   

<img src="Final_Report/Images/unitTestModules.jpeg" alt="unitTestModules" width="60%">

Unit testing is an important process in catching faulty components and poor design features before they are implemented in a more complete prototype product. When completed succesfully, this should benefit a project by reducing time and financial costs that would otherwise be spent repairing or redesigning defects.
The unit testing for our product comprises two main categories: hardware (motors/sensors) and software (driver C code), where the test results should confirm that both are working as expected.    
   

---
#### _Velocity and Steering_   
Velocity and steering is the most fundamental module for the autonomous car and provide the basic functionality necessary for movement in a 2D plane.   
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/RCCar07_Steering_and_Velocity_Unit_Code.c)   
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/RCCar7_Technical_Documentation.md)

* Test Objectives:
    - To confirm the hardware foundation of the car (motors, servo, H-bridge) are connected and functioning correctly.
    - To confirm the provided code is able to perform the basic movements: forward and reverse velocity, left and right steering.
* Test Plan:
    - The provided code 'RCCar07' will be compiled and loaded onto the Mbed microcontroller.
    - The program will be run and the car's behaviour observed.
* Pass Criteria:
    - The following functionality is observed:
        - Stop to full forward velocity
        - Full forward velocity to full reverse
        - Full reverse velocity to stop
        - Centre steering to full right
        - Full right steering to full left
        - Full left steering to centre
   
---
   

#### _IR Sensing_   
IR sensing allows the autonomous car to detect its position relative to the line it follows, and react accordingly. 
* [Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/IR_sensors_unit_code.c)
* [Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/IR_Sensor_Technical_Documentation.md)

---
#### _Temperature and Humidity Sensing_   
Temperature and humidity sensing gives the autonomous car the ability to monitor the surrounding ambient air conditions.   
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/temperature_and_humidity_unit_code.c)    
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/Temperature_and_Humidity_Sensor_Technical_Documentation.md)

* Test Objectives: 
    - To confirm the temperature/humidity sensor is operational and returns valid data readings.
    - To confirm external HTU21D.h library compatibility with Mbed LPC1768 platform.
    - To confirm pinouts are suitable.
* Test Plan:
    - The sensor will be connected to the Mbed pins 9 and 10 to allow I2C data transfer.
    - HTU21D library functions `sample_ctemp()` and `sample_humid()` will take ambient room temperature and humidity readings.
    - Data readings will be output to the system console for verification.
* Pass Criteria:
    - Valid temperature and humidity readings are displayed on system console.

Driver Code:
```
#include "mbed.h"
#include "HTU21D.h"
HTU21D temphumid(p9, p10);

int main() {
    while (1) {
        float temp = temphumid.sample_ctemp();
        float humidity = temphumid.sample_humid();

        printf("Temperature: %.2f C  Humidity: %.2f %%\n", temp, humidity);
        wait(0.5f);
    }
}
```

Results:   
<img src="Final_Report/Images/temphumid01.jpg" alt="TempHumid console output." width="35%">

---

#### _Ultrasonic Sensing_
* [Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/ultrasonic_sensor_unit_code.c)
* [Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/UltraSonic_Sensor_Technical_Documentation.md)

---
#### _Speaker Output_
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/speaker_unit_code.c)   
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/Speaker_Technical_Documentation.md)   

* Test Objectives: 
    - To confirm the speaker is operational and can output an audible alert sound.
* Test Plan:
    - The speaker will be connected to Mbed pin 23 to allow PWM control.
    - PwmOut Library function `period()` will be used to set output frequency of tone.
* Pass Criteria:
    - An audible alert tone is output from the speaker.
  
Driver Code (taken from https://simulator.mbed.com/):   
```
#include "mbed.h"

PwmOut speaker(p23);
// play a tone
void play_tone(float frequency, float volume, int interval, int rest) {
    speaker.period(1.0 / frequency);
    speaker = volume;
    wait(interval);
    speaker = 0.0;
    wait(rest);
}

int main()
{
    while(1) {
    play_tone(200.0, 0.5, 1, 0);
    }
}

```

Results:   


---
### Part 2: Integration Testing 
