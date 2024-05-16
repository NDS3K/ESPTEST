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

#define PS2_DAT 12 // MISO
#define PS2_CMD 13 // MOSI
#define PS2_SEL 15 // SS
#define PS2_CLK 14 // SLK

//Servo
#define servo_1 2
#define servo_2 3
#define servo_3 3
#define servo_4 4

int high_val = 4095;

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
void turn_left(){
    setPower(pin1_dc1,pin2_dc1,1);
    setPower(pin2_dc2,pin1_dc2,0);
}
void turn_right(){
    setPower(pin1_dc2,pin2_dc2,1);
    setPower(pin2_dc1,pin1_dc1,0);
}
void move_backward(){
    setPower(pin2_dc1,pin1_dc1,1);
    setPower(pin1_dc2,pin2_dc2,1);
}
void stop(){
    setPower(pin1_dc1,pin2_dc1,0);
    setPower(pin2_dc2,pin1_dc2,0);
}
void gamecon(){
    
    int y ;

    int leftr = ps2x.Analog(PSS_LX);

    y = map(leftr,0,255,0,4095);

}
