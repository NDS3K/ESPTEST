#include "Controller.h"
void setup(){
    initialize();
    setupPS2controller();
}
void loop()
{   
    ps2x.read_gamepad(false, false);
    controller();
}
