# Temperature and Humidity Sensor Technical Documentation
---
<img src="Final_Report/Images/temp_and_hum_sensor.png" alt="tem_and_hum_sensor_image." width="300" height="300">

Figure 1: HTU21D temperature and humidity sensor. 

The HTU21D is a digital humidity sensor with temperature capability. The sensor used the I<sup>2</sup>C interface to communicate with the LPC1768 microcontroller. 

Table 1: HTU21D pin connection table. 
| HTU21D signal pin name | mbed pin |
| ------ | ------ |
| 5V | Vout |
| GND (Ground) | GND |
| SDA | p9 |
| SCL | p10 |

Click [here](Product_Development/Software/Component_Unit_Test/temperature_and_humidity_unit_code.c) for unit test code for the HTU21D temperature and humidity sensor.

---
- The program makes use of a [HTU21D](https://os.mbed.com/users/mcm/code/HTU21D/file/ad5e3555c7ef/HTU21D.h/) digital humidity sensor with temerature output. 
- The temperature and humidity is designed to be implemented into a platform capable of analouge input from analouge devices. The mbed LPC1768 is capable of processing analouge inputs. 
- The code calls two function from the HTU21D.h to recoard temperature and humidity. 
---



### _Libraries_

`#include "mbed.h"`


`#include "HTU21D.h"`

### _AnalougeIn Pinouts_

`HTU21D temphumid(p9, p10);`

### _Functions_

**Temperature:**
```
// Getting temperature
float Get_Tem()
{
    int sample_ctemp = temphumid.sample_ctemp();

    return  sample_ctemp;
}
```
**Humidity:**
```
// Getting Humidity
float Get_Hum()
{
    int sample_humid = temphumid.sample_humid();

    return  sample_humid;
}
```

### _Implementation_

```
// Main body
while(1){

        while (Get_temp()> 30 ||Get_temp()< 15|| Get_Humd()> 0.75 ||Get_Humd()< 0.60 )
        {
            play_tone(200.0, 0.5, 1, 0);
            stop();
        }
}
```

