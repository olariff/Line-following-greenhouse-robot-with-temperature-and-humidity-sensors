# Temperature and Humidity Sensor Technical Documentation
<img src="Final_Report/Images/temp_and_hum_sensor.png" alt="tem_and_hum_sensor_image." width="300" height="300">

Figure 1: HTU21D temperature and humidity sensor. 

The HTU21D is a digital humidity sensor with temperature capability. The sensor used the I<sup>2</sup>C interface to communicate with the LPC1768 microcontroller. 


Click [here](Product_Development/Software/Component_Unit_Test/temperature_and_humidity_unit_code.c) for unit test code for the HTU21D temperature and humidity sensor.


- The program makes use of a [HTU21D](https://os.mbed.com/users/mcm/code/HTU21D/file/ad5e3555c7ef/HTU21D.h/) digital humidity sensor with temperature output. 
- The temperature and humidity is designed to be implemented into a platform capable of analouge input from analouge devices. The mbed LPC1768 is capable of processing analouge inputs. 
- The final program will call two function from the HTU21D.h to recoard temperature and humidity. 

---
---

### _Libraries_

`#include "mbed.h"`

- The mbed library header file is required for I<sup>2</sup>C interface communicate with the microcontroller pin I/O.

`#include "HTU21D.h"`
- The mbed libary is required inorder to call function to read temperature and humidity. 
- The libary can be used to call 

---
---

### _I<sup>2</sup>C Pinouts_

`HTU21D temphumid(p9, p10);`
- The HTU21D sensor module requires a I<sup>2</sup>C interface connection to communicate with the mbed LPC1768 board. 
- On the ARM mbed LPC1768 microcontroller pins p9 and p10 are I<sup>2</sup>C interface pins. 
- Table 1 shows how the respective pins of the HTU21D will be connected to mbed LPC1768 microcontroller. 

Table 1: HTU21D pin connection table. 
| HTU21D signal pin name | mbed pin |
| ------ | ------ |
| 5V | Vout |
| GND (Ground) | GND |
| SDA | p9 |
| SCL | p10 |

---
---

### _Functions_

**Temperature:**
```
// Getting temperature in Celsius
float Get_Tem()
{
    int sample_ctemp = temphumid.sample_ctemp();
    return  sample_ctemp;
}
```
 `int sample_ctemp = temphumid.sample_ctemp();` reads the temperature in degrees Celsius using the HTU21D sensor and stores the recoarded value in `sample_ctemp` variable. `.sample_ctemp();` is used to specifies the temperature should be recorded in degrees Celsius. `.sample_ftemp();` can be called to recoard temperature in Fahrenheit; alternatively, `.sample_ktemp();` can be used to obtain the temperature in Kelvin. For the purpose of this project, Celsius will be used as the temperature in the UK is commonly measured in Celsius temperature scale. It is important to note that other countries may use diffrent temperature scale. For example, in the USA temperature is commonly recoared in Fahrenheit temperature scale. 

| The equations below show different temperature sale:
| ------ | 
 - **Fahrenheit to Celsius:** _<sup>_O_</sup>C = (5/9)(<sup>_O_</sup>F - 32)_
- **Celsius to Fahrenheit:** _<sup>_O_</sup>F = (9/5)<sup>_O_</sup>C + 32_
- **Kelvin to Celsius:** _K = <sup>_O_</sup>C + 273.15_
- **Celsius to Kelvin** _<sup>_O_</sup>C = K - 273.15_
- **Fahrenheit to Kelvin:** _K = <sup>_O_</sup>F + 457.87_
- **Kelvin to Fahrenheit:** _<sup>_O_</sup>F = K - 457.87_

---

**Humidity:**
```
// Getting Humidity
float Get_Hum()
{
    int sample_humid = temphumid.sample_humid();
    return  sample_humid;
}
```
When `Get_Hum()` is called `int sample_humid = temphumid.sample_humid();` reads the humidity in from 0 to 1, where 0 representing 0% and 1 representing 100%. The result decimal number is stored in `sample_humid` variable. The `Get_Hum()` function returns humidity when called inside the main program. 

---
---

### _Implementation_

```
// LED1 on the mbed board
DigitalOut led(LED1); 

// Main body
int main(){

    while(1){
        while (Get_temp()> 30 ||Get_temp()< 15|| Get_Humd()> 0.75 ||Get_Humd()< 0.60 )
        {
            led = !led;
            wait_ms(500);
        }   
    }   
}
```
The code above call the `Get_Tem()` and `Get_Hum()` functions. While the temperature is not between 15 _<sup>_O_</sup>C_ and 30 _<sup>_O_</sup>C_ and the humidity is not between 60% and 75% the LED1 on the LPC1768 will flash with a period of 500ms, else the LED1 is off. The ideal temperature for strawberry growth is between 15 _<sup>_O_</sup>C_ and 30 _<sup>_O_</sup>C_ and the humidity must be between 60% and 75% (more information the the ideal temperature and humidity is found in [MVP product demonstration](Final_Report/MVP/MVP_Product_Demonstration.md) report). This is a simple and effective program to check if the HTU21D is working as intended and is producing the expected values. This program can be devloped further in this project to perform a set task if the temperature and humidity is output the ideal range in a greenhouse. 

| |
| ------ |
| ![Temperature and humidity test program GIF](Final_Report/flashing_LED.gif) |
| Figure 2: Ouput of the program while temperature and humidity are not in range. |

---

> [More information on the HTU21D humidity sensor with temperature capability](https://os.mbed.com/components/HTU21D-Temperature-and-Humidity-Sensor/) can be found on the hardware components libary of arm MBED. Click [here](https://os.mbed.com/users/alipford3/code/HTU21D_HELLOWORLD//file/8c0ef32974f0/main.cpp/) for more information on programmin with HTU21D sensor. 

