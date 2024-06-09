#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <PS2X_lib.h>
#include <stdio.h>
#include <stdlib.h>

#define pin1_dc1 8 
#define pin2_dc1 9 
#define pin1_dc2 10
#define pin2_dc2 11
#define pin1_dc3 12
#define pin2_dc3 13
#define pin1_dc4 14
#define pin2_dc4 15

//Servo
#define servo_1 2
#define servo_2 3
#define servo_3 3
#define servo_4 4

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

PS2X ps2x ;

void setPower(int pin1,int pin2,double x)
{
    pwm.setPWM(pin1,0,high_val*x);
    pwm.setPWM(pin2,0,0);
}
void move_forward()
{
    setPower(pin1_dc1,pin2_dc1,1);
    setPower(pin2_dc2,pin1_dc2,1);
}

