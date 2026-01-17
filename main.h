
#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "washing_machine_function_def.h"
#include "clcd.h"
#include "digital_keypad.h"
#include "timers.h"
#define reset_screen       0x11
#define reset_nothing      0xFF
#define reset_water_level_screen    0x22
#define washing_program_screen      0x01
#define water_level          0x02
#define start_or_stop       0x03
#define reset_start_screen      0x33
#define start_screen            0x04
#define fan_ddr             TRISC2
#define buzzer_ddr          TRISC1
#define buzzer              RC1
#define fan                 RC2
#define on                  1
#define off                 0
#define pause               0x44


#endif	

