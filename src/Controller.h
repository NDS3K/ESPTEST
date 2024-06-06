#include <Configs.h>

#define PS2_DAT 12 // MISO
#define PS2_CMD 13 // MOSI
#define PS2_SEL 15 // SS
#define PS2_CLK 14 // SLK

PS2X ps2x ;

int y = 128 ;
int x = 127 ;

void setupPS2controller()
{
    int error = -1 ;
    while(error != 0)
    {
        error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
        Serial.println(error);
    }
}

void setPower(int pin1,int pin2,int x)
{
    pwm.setPWM(pin1,0,x);
    pwm.setPWM(pin2,0,0);
}

//Base
void move_forward(int x)
{
    setPower(pin1_dc1,pin2_dc1,x);
    setPower(pin2_dc4,pin1_dc4,x);
}
void turn_left(int x)
{
    setPower(pin1_dc1,pin2_dc1,x);
    setPower(pin2_dc4,pin1_dc4,0);
}
void turn_right(int x)
{
    setPower(pin2_dc4,pin1_dc4,x);
    setPower(pin2_dc1,pin1_dc1,0);
}
void move_backward(int x)
{
    setPower(pin2_dc1,pin1_dc1,x);
    setPower(pin1_dc4,pin2_dc4,x);
}
void stop()
{
    setPower(pin1_dc1,pin2_dc1,0);
    setPower(pin2_dc4,pin1_dc4,0);
}

//Intake
void intake_run(int x)
{
    setPower(pin1_dc3,pin2_dc3,x);
}
void intake_stop()
{
    setPower(pin1_dc3,pin2_dc3,0);
}
void intake_reverse(int x)
{
    setPower(pin2_dc3,pin1_dc3,x);
}

//Climber
void climber_forward(int x)
{
    setPower(pin1_dc2,pin2_dc2,x);
}
void climber_reverse(int x) 
{
    setPower(pin2_dc2,pin1_dc2,x);
}
void climber_stop()
{
    setPower(pin1_dc2,pin2_dc2,0);
}

//Control
void controller()
{   
    //Joystick Setting Up
    int ly = ps2x.Analog(PSS_LY);
    int rx = ps2x.Analog(PSS_RX); 
    int ly_raw = y - ly;
    int rx_raw = x - rx; 
    int ly_val = abs(ly_raw);
    int rx_val = abs(rx_raw);
    int ly_po = map(ly_val,0,128,0,4095);
    int rx_po = map(rx_val,0,128,0,4095);

    //Base Control
    if(ly_raw > 0)
    {
        move_forward(ly_po);
    }
    else if(ly_raw < 0)
    {
        move_backward(ly_po);
    }
    else if(rx_raw > 0)
    {
        turn_left(rx_po);
    }
    else if(rx_raw < 0)
    {
        turn_right(rx_po);
    }
    else
    {
        stop();
    }

    //Intake Control
    if(ps2x.Button(PSB_L1))
    {
        intake_stop();
    }
    else if (ps2x.Button(PSB_TRIANGLE))
    {
        intake_reverse(4095);
    }
    else
    {
        intake_run(4095); 
    }

    //Climber Control
    if(ps2x.Button(PSB_PAD_UP))
    {
        climber_forward(3000);
    }
    else if(ps2x.Button(PSB_PAD_DOWN))
    {
        climber_reverse(3000);
    }
    else
    {
        climber_stop();
    }

}
