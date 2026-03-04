#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/EXT/EXT_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

volatile unsigned char toggle_flag = 0;
void Toggle_LED()
{
    toggle_flag = 1;
}

void main()
{
    LED_Init(GPIO_PORTC,0);
    SWITCH_Init(GPIO_PORTB,0);

    EXT_INT0_Init();
    EXT_INT0_SetCallback(Toggle_LED);

    while(1)
    {
             if (toggle_flag ==1){
                LED_Toggle(GPIO_PORTC, 0);
                toggle_flag = 0;
             }
    }
}