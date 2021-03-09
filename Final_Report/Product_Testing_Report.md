Test report

Testing performed
This section should describe your test plans, and results.
Every test should have a clear goal so that pass/fail can be indicated against all tests actually performed.
For some tests, it is a good idea to use screenshots of target and actual results.
You should research testing to set your testing within the known methodologies.

Automatic Testing:
Describe any JUnit tests you created. Describe what percentage of program functionality is covered by JUnit tests.
Highlight any functionality not covered by JUnit tests, and say how you overcame that shortfall.
Describe if you managed to use the continuous integration server to run tests - which tests were run, and what were the results?


# Product Test Report   
The following report details the various tests used to assess the product and its component parts.    
(Note: With lockdown restrictions imposed due to Covid-19, many tests were not possible to conduct physically - in this situation the team has continued with assumed ideal test results).

---
### Unit Testing
Unit testing is an important process in catching faulty components and poor design features before they are implemented in a more complete prototype product. When completed succesfully, this should benefit a project by reducing time and financial costs that would otherwise be spent repairing or redesigning defects.
The unit testing for our product comprises two main categories: hardware (motors/sensors) and software (driver C code), where the test results should confirm that both are working as expected. 

#### _Velocity and Steering_
* [Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/RCCar07_Steering_and_Velocity_Unit_Code.c)
* [Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/RCCar7_Technical_Documentation.md)

#### _IR Sensing_
* [Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/IR_sensors_unit_code.c)
* [Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/IR_Sensor_Technical_Documentation.md)

---
#### _Temperature and Humidity Sensing_
[Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/temperature_and_humidity_unit_code.c)    
[Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/Temperature_and_Humidity_Sensor_Technical_Documentation.md)

* Test Objectives: 
    - To confirm the temperature/humidity sensor is operational and returns valid data readings.
    - To confirm external HTU21D.h library compatibility with Mbed LPC1768 platform.
    - To confirm pinouts are suitable.
* Test Plan:
    - The sensor will be connected to the Mbed microcontroller pins 9 and 10 to allow I2C data transfer.
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
#### _Ultrasonic Sensing_
* [Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/ultrasonic_sensor_unit_code.c)
* [Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/UltraSonic_Sensor_Technical_Documentation.md)

#### _Speaker Output_
* [Unit Code](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Component_Unit_Test/speaker_unit_code.c)
* [Technical Documentation](https://cseegit.essex.ac.uk/2020_ce293/ce293_team01/-/blob/master/Product_Development/Software/Technical_Documentations/Speaker_Technical_Documentation.md)
---

