# Speaker Technical Documentation 

![Image of speaker](Final_Report/Images/speaker_image.png)

Figure 1: Speaker. The images is sources from [CUI Devices](https://jp.cuidevices.com)

Speaker is a electric transducer which, converts an electrical audio signal into a corresponding sound.

---
---

### _Libraries_

`#include "mbed.h"`

- The mbed library header file is required for PWM pin communicate with the microcontroller pin I/O.

---
---

### _PWM Pinouts_

- The speaker uses PWM pin output of the mbed board as it requires electronic signal to convert an electric signal into a corresponding sound. 
- The PWM pin allows the pitch and tone of the speaker to be controlled.  
- The speaker used for line follower peoject is a dynamic speaker with positive and negative input. 
    - The positive input of the speaker is connected to pin 21 on the mbed LPC1768 board. 
    - The negative input of the speaker is connected to ground (GND) rail of a circuit. 

Table 1: Speaker pin connection table. 
| HTU21D signal pin name | mbed pin |
| ------ | ------ |
| Positive (red) | p21 |
| GND (black) | GND |

---
---

### _Functions_

```
void play_tone(float frequency, float volume, int interval, int rest) {
    speaker.period(1.0 / frequency);
    speaker = volume;
    wait(interval);
    speaker = 0.0;
    wait(rest);
}
```
The `play_tone()` function takes in frequency, volume, interval and rest as parameter. The function plays the speaker for a set interval and at which point it will turn off until the function is called again. 

### _Implementation_

`play_tone(200.0, 0.5, 1, 0);` function call sets the frequency as 200Hz, the volume is 50% (0.5), the period of the frequency is set to 1 second and the rest time is set to 0 seconds. The rest time can be increased to provide a delay between playing diffrent sounds through the speaker.
