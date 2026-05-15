#include "project.h"

pi_joystick_t* joystick = NULL;

void open_input(void){
    if(joystick == NULL){
     joystick = getJoystickDevice();
    }

}

void close_input(void){
     if(joystick != NULL){
     	freeJoystick(joystick);
     	joystick = NULL;
     }

}

void check_input(void (*callback)(unsigned int code), int delay){
	pollJoystick(joystick, callback, delay );
}
