#include "EXT_interface.h"


static void (*INT0_Callback)(void) = 0;

void EXT_INT0_Init(void)
{
    OPTION_REG.INTEDG = 0;

    INTCON.INTF = 0;
    INTCON.INTE = 1;
    INTCON.GIE = 1;
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    INT0_Callback = ptr;
}


void interrupt()
{
    if(INTCON.INTF == 1)
    {
        if(INT0_Callback != 0)
        {
            INT0_Callback();
        }

        INTCON.INTF = 0;
    }
}
