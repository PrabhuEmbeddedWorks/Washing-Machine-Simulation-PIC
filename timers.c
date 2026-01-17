#include <xc.h>
#include "timers.h"

void init_timer2(void)
{
    
   
    TMR2IE = 1;
    TMR2ON=0;
    PR2 = 250;
    
    
}
