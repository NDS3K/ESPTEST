#include "Configs.h"

long x = 0 ;

int low_val = 0 ;

void setup(){
    Serial.begin(115200);
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    bool pressures,rumble = false;
    int error = -1 ;
    for(int i = 0; i  <= 10; i++)
    {
        delay(1000);
        error = ps2x.config_gamepad(PS2_CLK,PS2_CMD,PS2_SEL,PS2_DAT,pressures,rumble);
        Serial.print(".");
        if(!error)
        {
            break;
        }

    }
}

void loop()
{
    ps2x.read_gamepad(false, false);

    if(ps2x.Button(PSB_PAD_UP))
    {
        move_forward();    
    }
    else
    {
        stop();
    }  
    if(ps2x.Button(PSB_TRIANGLE))
    {
        pwm.setPWM(servo_1,0,410);
        Serial.println("Triangle is pressed");
    }
    else
    {
        pwm.setPWM(servo_1,0,0);
    }
}


