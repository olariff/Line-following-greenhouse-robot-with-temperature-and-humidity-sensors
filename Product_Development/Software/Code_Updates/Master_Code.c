#include "mbed.h"
#include "HTU21D.h"
#include "ultrasonic.h"

HTU21D temphumid(p9, p10);      //Temprature & Humidty sensor using I2C (SDA, SCL)

ultrasonic mu(p7, p8, .1, 1, &Detecting_Objects);    //trigger:p9, echo:p8
                                                     //have updates every .1 seconds and a timeout after 1
                                                     //second, and call Detecting_Objects when the distance changes

PwmOut steering(p21);               // steering pin
PwmOut velocity(p22);               // velocity pin
PwmOut speaker(p23);                // speaker pin

AnalougeIn left_sensor(p15);        // left light sensor
AnalougeIn right_sensor(p16);       // right light sensor



float Dis;                          // Current Distance away from the closest object
float curVelocity = 0.0;            // Current Velocity
float curWheelAngle = 0.0;          // Current Wheel Angle


// Updating the vearialble Dis
void Detecting_Objects(float distance)
{
    Dis = distance;
}

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

// Turning the car [turn(1) for fully right, turn(-1) for fully left]
void turn(float t)
{
    if (t++>=0 && t<=2) {steering.pulsewidth(t/2000+0.001);}                    // convert steering angle into a pulsewidth
    curWheelAngle = t;                                                          // set current Wheel Angle
}

// setting the speed of the car [drive(1)for max forward speed, drive(-1)for max backward speed]
void drive(float v)
{
    if (v++>=0 && v<=2) {velocity.pulsewidth(v/2000+0.001);}                    // convert velocity into a pulsewidth
    curVelocity = v;                                                            // set current velocity
}

// Stopping the car
void stop()
{
    drive(0.0);                                                                 // Setting the Velociy of the car to zero
    curVelocity = 0.0;                                                          // set current velocity to 0;
}

// Checking the right and the left sensor
void Check_sensor();
{
    if (right_sensor.read()>0.5)                    // The car has facing towards the left of the line
    turn(1);// turn right
    if (left_sensor.read()>0.5)                     // The car has facing towards the right of the line
    turn(-1); // turn left
    if (!turn_right.read() && !turn_left.read())    //The car is facing forward
    turn(0.0); // stop turning
}




int main() {

    drive (0.2);      // Setting the speed to 20% of the maximum forward speed

    mu.startUpdates();//start mesuring the distance

    while (1)
    {
        int flag;

        Check_sensor();

        while (Get_temp()> 30 ||Get_temp()< 15|| Get_Humd()> 0.75 ||Get_Humd()< 0.60 )
        {
                play_tone(200.0, 0.5, 1, 0);
                stop();
                flag = 1;
        }

        mu.checkDistance();

        while (dis < 0.5)
        {
                play_tone(200.0, 0.5, 1, 0);
                stop();
                mu.checkDistance();
                flag =1;
        }

        if (flag)
        {
            drive(0.2);
            flag =0;
        }

    }

return 0;
}
