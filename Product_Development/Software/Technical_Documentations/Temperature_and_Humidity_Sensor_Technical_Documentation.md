# Temperature and Humidity Sensor Technical Documentation
---

Click [here](Product_Development/Software/Component_Unit_Test/temperature_and_humidity_unit_code.c) for unit test code for the temperature and humidity sensor.

---
- The temperature and humidity is designed to be implemented into a platform capable of analouge input from analouge devices. The mbed LPC1768 is capable of processing analouge inputs. 
- The code 
-
---

### _Libraries_

`#include "mbed.h"`

`#include "HTU21D.h"`


### _AnalougeIn Pinouts_

`HTU21D temphumid(p9, p10);`

### _Functions_

##### Temperature: 
```
// Getting temperature
float Get_Tem()
{
    int sample_ctemp = temphumid.sample_ctemp();

    return  sample_ctemp;
}
```
##### Humidity: 
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

