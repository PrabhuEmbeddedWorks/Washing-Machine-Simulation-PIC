
#include"main.h"
extern unsigned int reset_flag;
extern unsigned int operational_state;

char *washing_program[] = {"Daily", "Heavy" , "Dedicates", "Whites",
"Stain wash" , "Eco cottons", "Woolens" , "Bed sheets", "Rinse+Dry" , 
"Dry only", "Wash only" , "Aqua store"};

unsigned char program_no = 0;
unsigned char level=0;
char *water_level_options[]={"AUTO", "LOW", "MEDIUM", "HIGH", "MAX"};
unsigned char sec,min;
unsigned char total_time , wash_time , rinse_time , spin_time, time;

void power_ON_screen(void){
    for(unsigned int i=0;i<16;i++){
        clcd_putch(block, (unsigned char)LINE1(i));
        __delay_ms(100);
    }
    
    clcd_print("Powering ON",LINE2(3));
    clcd_print("Washing Machine",LINE3(1));
    
    for(unsigned int i=0;i<16;i++){
       clcd_putch(block, (unsigned char)LINE4(i));
        __delay_ms(100);
    }
}

void clear_clcd(void){
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}


void washing_program_(unsigned char key){
    if(reset_flag == reset_screen){
        clear_clcd();
        reset_flag= reset_nothing;
    }
    if(key == SW4){  // Only short press scrolls
    clear_clcd();
    program_no = (program_no + 1) % 12;
}

    clcd_print("Washing program",LINE1(0));
    clcd_putch('*' , LINE2(0));
    
    if(program_no<=9){
      clcd_print(washing_program[program_no],LINE2(1));
      clcd_print(washing_program[program_no+1],LINE3(1));
      clcd_print(washing_program[program_no+2],LINE4(1));
    }
    else if(program_no==10){
      clcd_print(washing_program[program_no],LINE2(1));
      clcd_print(washing_program[program_no+1],LINE3(1));
      clcd_print(washing_program[0],LINE4(1));  
    }
    else if(program_no==11){
      clcd_print(washing_program[program_no],LINE2(1));
      clcd_print(washing_program[0],LINE3(1));
      clcd_print(washing_program[1],LINE4(1));  
    }
}

void water_level_screen(unsigned char key){
    if( reset_flag == reset_water_level_screen){
        clear_clcd();
        reset_flag = reset_nothing;
    }
    
    if(key == SW4){  // Only short press scrolls
    clear_clcd();
    level = (level + 1) % 5;
}

    
    clcd_print("WATER LEVEL",LINE1(0));
    clcd_putch('*',LINE2(0));
    clcd_print(water_level_options[level],LINE2(1));
    clcd_print(water_level_options[(level+1)%5],LINE3(1));
    clcd_print(water_level_options[(level+2)%5],LINE4(1));
}

void set_time(void){
    switch(program_no){
        case 0: //daily
            switch(level){
                case 1: sec = 33;
                min=0;
                    break;
                case 0:
                case 2: sec = 41;
                min=0;
                    break;
                case 3:
                case 4: sec = 45;
                min=0;
                    break;
            }
            break;
        case 1://heavy
            switch(level){
                case 1: 
                    min=0;
                    sec = 40;
                    break;
                case 0:
                case 2:
                    min=0;
                    sec = 50;
                    break;
                case 3:
                case 4:
                    min=0;
                    sec = 57;
                    break;
            }
            break;
        case 2://delicates
            switch(level){
                case 1: 
                case 0:
                case 2:
                    min=0;
                    sec = 26;
                    break;
                case 3:
                case 4:
                    min=0;
                    sec = 31;
                    break;
            }
            break;
        case 3://Whites
            switch(level){
                case 1: 
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 1;
                    sec = 16;
                    break;
            }
            break;
        case 4://stain wash
            switch(level){
                case 1: 
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 1;
                    sec = 36;
                    break;
            }
            break;
        case 5://eco cottons
            switch(level){
                case 1: 
                case 0:
                case 2:
                    min=0;
                    sec=31;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 36;
                    break;
            }
            break;
        case 6://Woolens
            switch(level){
                case 1: 
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 29;
                    break;
            }
            break;
        case 7://Bed sheets
            switch(level){
                case 1: 
                    min=0;
                    sec=46;
                    break;
                case 0:
                case 2:
                    min=0;
                    sec=53;
                    break;
                case 3:
                case 4:
                    min = 1;
                    sec = 0;
                    break;
            }
            break;
        case 8://Rinse+Dry
            switch(level){
                case 1: 
                    min=0;
                    sec=18;
                    break;
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 20;
                    break;
            }
            break;
        case 9://Dry only
            switch(level){
                case 1: 
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 6;
                    break;
            }
            break;
        case 10://Wash only
            switch(level){
                case 1: 
                    min=0;
                    sec=16;
                    break;
                case 0:
                case 2:
                    min=0;
                    sec=21;
                    break;
                case 3:
                case 4:
                    min = 0;
                    sec = 21;
                    break;
            }
            break;
        case 11://Aqua store
            switch(level){
                case 1: 
                case 0:
                case 2:
                case 3:
                case 4:
                    min = 0;
                    sec = 50;
                    break;
            }
            break;
            
    }
}

void start(unsigned char key){
    door_status_check();
    if(reset_flag == reset_start_screen){
        clear_clcd();
        clcd_print("Prog:",LINE2(0));
        clcd_print(washing_program[program_no],LINE2(6));
        clcd_print("TIME:",LINE3(0));
        clcd_putch(min/10 +'0',LINE3(6));
        clcd_putch(min%10 + '0',LINE3(7));
        clcd_putch(':',LINE3(8));
        clcd_putch(sec/10 +'0',LINE3(9));
        clcd_putch(sec%10 + '0',LINE3(10));
        reset_flag = reset_nothing;
        
        __delay_ms(2000);
        clear_clcd();
        
        clcd_print("FUNCTION: ",LINE1(0));
        clcd_print("Time",LINE2(0));
        clcd_print("RB4: START",LINE3(0));
        clcd_print("RB5: PAUSE",LINE4(0));
        total_time = time = min*60+sec;
        wash_time  = (total_time * 46) / 100;
        rinse_time = (total_time * 12) / 100;
        spin_time  = (total_time * 42) / 100;

        TMR2ON = 1;//turn on timer
        fan = on;
    }
    
    if( key == SW6 ){
            TMR2ON = 0;
            fan = off;
            operational_state = pause;
        }
    
    
    total_time= min*60+sec;
    if(program_no<=7){
        if(total_time >= (time - wash_time)){
            clcd_print("Wash",LINE1(10));
        }
        else if(total_time >= time - wash_time - spin_time){
            clcd_print("Rinse",LINE1(10));
        }
        else{
            clcd_print("Spin ",LINE1(10));
        }
    }
    else if(program_no == 8){
        if(total_time >= (time - (0.40*time))){
            clcd_print("Rinse",LINE1(10));
        }
        else{
            clcd_print("Spin ",LINE1(10));
        }
    }
    else if(program_no == 9){
        clcd_print("Spin ",LINE1(10));
    }
    else{
        clcd_print("Wash",LINE1(10));
    }
    clcd_putch(min/10 +'0',LINE2(6));
        clcd_putch(min%10 + '0',LINE2(7));
        clcd_putch(':',LINE2(8));
        clcd_putch(sec/10 +'0',LINE2(9));
        clcd_putch(sec%10 + '0',LINE2(10));
        if(min ==0 && sec == 0){
            clear_clcd();
            fan=off;
            buzzer=on;
            clcd_print("Program complete", LINE1(0));
            clcd_print("Remove cloths", LINE2(0));
            __delay_ms(2000);
            buzzer = off;
            operational_state=washing_program_screen;
             reset_flag=reset_screen;
             clear_clcd();
        }
}


void door_status_check(void){
    if( RB0 == 0){
        //if switch1 is pressed the door is opened
        fan = off;
        TMR2ON = 0;
        buzzer = on;
        clear_clcd();
        clcd_print("DOOR IS OPEN",LINE1(0));
        clcd_print("Plz close door",LINE2(0));
        //wait untill the door is closed
        //need to wait till the switch is released
        while(RB0 == 0){
            ;//waiying for door close
        }
        fan = on;
        TMR2ON = 1;
        buzzer = off;
        clear_clcd();
        clcd_print("FUNCTION: ",LINE1(0));
        clcd_print("Time",LINE2(0));
        clcd_print("RB4: START",LINE3(0));
        clcd_print("RB5: PAUSE",LINE4(0));
    }
}

