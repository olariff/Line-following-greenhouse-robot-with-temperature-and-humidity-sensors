#include "mbed.h"
#include "HTU21D.h"

HTU21D temphumid(p9, p10);
PwmOut speaker(p23); 

// playing a tone
void play_tone(float frequency, float volume, int interval, int rest) {
    speaker.period(1.0 / frequency);
    speaker = volume;
    wait(interval);
    speaker = 0.0;
    wait(rest);
}

// Getting temperature
float Get_Tem()
{
    int sample_ctemp = temphumid.sample_ctemp();

    return  sample_ctemp;
}

// Getting Humidity
float Get_Hum()
{
    int sample_humid = temphumid.sample_humid();

    return  sample_humid;
}

// Main body
while(1){

        while (Get_temp()> 30 ||Get_temp()< 15|| Get_Humd()> 0.75 ||Get_Humd()< 0.60 )
        {
                play_tone(200.0, 0.5, 1, 0);
                stop();
        }
}
