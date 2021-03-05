#include "mbed.h"
#include "ultrasonic.h"

ultrasonic mu(p7, p8, .1, 1, &Detecting_Objects);
PwmOut speaker(p23); 

// playing a tone
void play_tone(float frequency, float volume, int interval, int rest) {
    speaker.period(1.0 / frequency);
    speaker = volume;
    wait(interval);
    speaker = 0.0;
    wait(rest);
}

// Get Distance
void Detecting_Objects(float distance)
{
    Dis = distance;
}

// Main body
while(1){

    mu.checkDistance();

    while (dis < 0.5)
    {
            play_tone(200.0, 0.5, 1, 0);
            stop();
            mu.checkDistance();
    }
}