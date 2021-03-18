# Product Test Report   
The following report details the various tests used to assess the autonomous car's performance.    
(Note: With lockdown restrictions imposed due to Covid-19, many tests were not possible to conduct physically - in this situation the team has used simulations where possible or continued with assumed ideal test results).  

Contents:
* [Part 1: Unit Testing](#part-1-unit-testing)
    - [Velocity and Steering](#velocity-and-steering)   
    - [Infrared Sensing](#ir-sensing)   
    - [Temperature and Humidity Sensing](#temperature-and-humidity-sensing)
    - [Ultrasonic Sensing](#ultrasonic-sensing)   
    - [Speaker Output](#speaker-output)   
* [Part 2: Integration Testing](#part-2-integration-testing)
    - [Velocity/Steering, Infrared, and Ultrasonic](#velocitysteering-infrared-and-ultrasonic)
    - [Temperature/Humidity & Speaker Output](#temperaturehumidity-and-speaker-output)
* [Part 3: System Testing](#part-3-system-testing)




---
### Part 1: Unit Testing   

<img src="Final_Report/Images/unitTestModules.jpeg" alt="unitTestModules" width="60%">

Unit testing is an important process in catching faulty components and poor design features before they are implemented in a more complete prototype product. When completed succesfully, this should benefit a project by reducing time and financial costs that would otherwise be spent repairing or redesigning defects.   
   
Unit testing for our product will focus on the 5 main modules it comprises: 
* Velocity and Steering
* Infrared Sensing
* Temperature and Humidity Sensing
* Ultrasonic Sensing
* Speaker Ouput   
   
Since these modules consist of both hardware (motors/sensors) and software (driver C code) components, testing must confirm that both work as expected.  
   

---
#### _Velocity and Steering_   
Velocity and steering is the most fundamental module for the autonomous car and provide the basic functionality necessary for movement in a 2D plane (linear velocity and heading).   
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

Results:   
* Unit Test Passed:
    - The test was conducted remotely over Zoom and the car was seen to perform the required functions listed above.   
    - It was noted that the velocity of the car would need to be reduced for use in our application.   

<img src="Final_Report/Images/car.jpg" alt="car" width="60%">
   
---
   

#### _IR Sensing_   
IR sensing allows the autonomous car to detect its position relative to its guide line, and update its velocity/heading accordingly.    
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/IR_sensors_unit_code.c)   
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/IR_Sensor_Technical_Documentation.md)  

* Test Objectives:
    - To confirm both IR sensors are operational and capable of returning valid readings in response to changing light.
* Test Plan:
    - The IR sensor will be connected to Mbed pins 15 and 16 to allow analogue data to be read from each sensor.
    - `read()` functions will take data readings from each sensor while exposed to changin light conditions.
    - The data readings will be printed to the system console for verification.
* Pass Criteria:
    - Valid light readings from each sensor are displayed on the system console.
    

---
#### _Temperature and Humidity Sensing_   
Temperature and humidity sensing gives the autonomous car the ability to monitor the surrounding ambient air conditions.   
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/temperature_and_humidity_unit_code.c)    
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/Temperature_and_Humidity_Sensor_Technical_Documentation.md)

* Test Objectives: 
    - To confirm the temperature/humidity sensor is operational and returns valid data readings.
    - To confirm external `HTU21D.h` library compatibility with Mbed LPC1768 platform.
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
* Unit Test Passed:
    - The sensor successfully measured room's ambient temperature and humidity.
    - Data readings were verified on the system console.   
<img src="Final_Report/Images/temphumid01.jpg" alt="TempHumid console output." width="35%">

---

#### _Ultrasonic Sensing_   
Ultrasonic sensing provides the ability to detect obstructions in the autonomous car's path so that velocity/heading can be updated accordingly.     
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/ultrasonic_sensor_unit_code.c)   
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/UltraSonic_Sensor_Technical_Documentation.md)   

* Test Objectives:
    - To confirm the sensor unit is operational and can return valid distance readings in response to the proximity to other objects.
    - To confirm external `ultrasonic.h` library compatibility with Mbed LPC1768 platform.
    - To confirm chosen pinouts are suitable.
* Test Plan:
    - The sensor will be connected to Mbed pin 7 (to use clock signal) and pin 8 (for data readings).
    - Ultrasonic library function `checkDistance()` will take data readings as an object is moved towards the sensor.
    - Data readings will be output to the system console for verification.
* Pass Criteria:
    - Valid data readings are displayed on the system console.   
   
Driver Code:   
```
#include "mbed.h"
#include "ultrasonic.h"

ultrasonic mu(p7, p8, .1, 1, &Detecting_Objects);
 
// Get Distance
void Detecting_Objects(float distance){
    Dis = distance;
}

while(1){
    mu.checkDistance();
    printf("Distance: %.3f", dis);
}
```
Results:   
* Unit Test Passed:
    - The sensor detected an approaching object.
    - Readings were verified on the system console.
<img src="Final_Report/Images/ultrasonic01.jpg" alt="Ultrasonic console output" width="15%">   
   
---
#### _Speaker Output_   
The speaker gives the car the ability to sound an audible warning if it detects ambient conditions outside of the desired temperature/humidity ranges.      
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
* Unit test passed:
    - an audible tone was heard from the speaker.


---
---
### Part 2: Integration Testing    

<img src="Final_Report/Images/intTestModules.jpeg" alt="intTestModules" width="50%">   

Integration testing allows related modules to be combined and tested together before being added into a final and complete system. For out project there are two main areas we would like have tested:
* Velocity/Steering, Infrared, and Ultrasonic    
* Temperature/Humidity, and Speaker Output   
   
It has not been possible to simulate or carry out these tests; this section details how the proposed tests could have been carried out.   
   

---
   
#### _Velocity/Steering, Infrared, and Ultrasonic_
This integrated system will control the car's movement as in follows its guideline and encounters potential obstructions.    
   

---


#### _Temperature/Humidity and Speaker Output_   
This integrated system should detect temperatures and humidities outside of the desired ranges:   
* For temperature this is is anything outside of 15°C - 30°C.   
* For humidity this is anything outside of 60% - 75%.   

To test this functionality, it would be necessary to connect the speaker and sensor to the Mbed controller, and expose the the sensor to different environmental conditions. For temperatures, this could be done by using a hair dryer to warm the sensor above 30°C, or (season permitting) testing outside on a cool day below 15°C.   
For humidities, this could be done by testing in a small room while a saucepan of water boils nearby (to create localised high humidity) or near a dehumidifier (to create localised low humidity). 
   
Proposed driver code:   
```

#include "HTU21D.h"
#include "mbed.h"

PwmOut speaker(p23);
HTU21D temphumid(p9, p10);

// play a tone
void play_tone(float frequency, float volume, int interval, int rest) {
    speaker.period(1.0 / frequency);
    speaker = volume;
    wait(interval);
    speaker = 0.0;
    wait(rest);
}

// Main body
int main(){

    // if temp/humidity outside of range: play warning tone from speaker
    while(1){
        while (temphumid.sample_ctemp() > 30 ||temphumid.sample_ctemp() < 15|| temphumid.sample_humid() > 0.75 ||temphumid.sample_humid() < 0.60 ){
            play_tone(200.0, 0.5, 1, 0);
            wait_ms(500);
        }   
    }   
}

```
---
---
### Part 3: System Testing

<img src="Final_Report/Images/systemTestModules.jpeg" alt="systemTestModules" width="50%">   
