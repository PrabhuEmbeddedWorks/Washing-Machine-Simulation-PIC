

#ifndef WASHING_MACHINE_FUNCTION_DEF_H
#define	WASHING_MACHINE_FUNCTION_DEF_H

void power_ON_screen(void);
void clear_clcd(void);
void washing_program_(unsigned char key);
void water_level_screen(unsigned char key);
void start(unsigned char key);
void set_time(void);
void door_status_check(void);

#endif	
