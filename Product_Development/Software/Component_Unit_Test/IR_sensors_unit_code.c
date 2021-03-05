#include "mbed.h"

AnalougeIn left_sensor(p15);
AnalougeIn left_sensor(p16);
PwmOut steering(p21);

// Steering expects -1 (left) to +1 (right)
void Steering(float s) {
    s=s+1;
    if (s>=0 && s<=2) {
        steering.pulsewidth(s/2000+0.001);
    }
}

void turn(float t)
{
    if (t++>=0 && t<=2) {steering.pulsewidth(t/2000+0.001);}                    // convert steering angle into a pulsewidth
    curWheelAngle = t;                                                          // set current Wheel Angle
}


int main(1)()
{

    /* Optional: set mode as PullUp/PullDown/PullNone/OpenDrain */
    left_sensor.mode(PullNone);
    right_sensor.mode(PullNone);

    while(1) {
        
        if (left_sensor.read() == 0) {
            turn(1); 
        } else if(right_sensor.read() == 0){
            turn(-1);
        } else if (left_sensor.read() == 1 && right_sensor == 1 ) {
            turn(0.0); 
        }
    }
}
