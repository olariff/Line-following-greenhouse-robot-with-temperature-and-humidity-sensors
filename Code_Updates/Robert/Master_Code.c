#include "mbed.h"
#include "HTU21D.h"
#include "ultrasonic.h"

HTU21D temphumid(p9, p10); //Temp humid sensor || SDA, SCL
PwmOut steering(p21);           // steering modification
PwmOut velocity(p22);           // velocity modification
PwmOut speaker(p23); // 

DigitalIn left_sensor(p7);
DigitalIn right_sensor(p8);


ultrasonic mu(p27, p28, .1, 1, &dist);    //Set the trigger pin to D8 and the echo pin to D9
                                        //have updates every .1 seconds and a timeout after 1
                                        //second, and call dist when the distance changes
                                        
                                        

void play_tone(float frequency, float volume, int interval, int rest) {
    speaker.period(1.0 / frequency);
    speaker = volume;
    wait(interval);
    speaker = 0.0;
    wait(rest);
}


float curVelocity = 0.0;
float curWheelAngle = 0.0;

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

void turn(float t)
{ // right (1) left (-1)
    if (t++>=0 && t<=2) {steering.pulsewidth(t/2000+0.001);}                    // convert steering angle into a pulsewidth
    curWheelAngle = t;
}
    
void drive(float v){// forward (1), backward (-1)
    if (v++>=0 && v<=2) {velocity.pulsewidth(v/2000+0.001);}                    // convert velocity into a pulsewidth
    curVelocity = v;                                                            // set current velocity
   
}
 
void stop()
{
    drive(0.0);                                                                 // Reduce speed to 0, regardless of direction car is travelling
    curVelocity = 0.0;
}

void Check_sensor();
{
    if (right_sensor)
    turn(1);// turn right
    if (left_sensor)
    turn(-1); // turn left
    if (!turn_right && !turn_left)
    turn(0.0); // stop turning  
}




int main() {
    
    drive (0.2);
     mu.startUpdates();//start mesuring the distance
     
    while (1)
    {
        while (Get_temp()> 30 ||Get_temp()< 15|| Get_Humd()> 0.75 ||Get_Humd()< 0.60 )
        {
                play_tone(200.0, 0.5, 1, 0);
                stop();
        }
        
        while (mu.getCurrentDistance() < 0.5)
        {
                play_tone(200.0, 0.5, 1, 0);
                stop();
        }  
        
        Check_sensor();        
        
    }
       
return 0;
}
