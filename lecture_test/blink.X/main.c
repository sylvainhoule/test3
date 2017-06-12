/******************************************************************************
 * FileName:     main.c 
 *	 
 *
 * Description:    This project intends to implement an blinking LED.
 *
 * REVISION HISTORY:
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author       	Date                Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Jason Robinson   June 08 2017        v1.0.0	First version. 
 *												Set configuration of the system 
 * John Carter      June 10 2017        v1.0.1	Configure a LED and blink it
 *												in the while loop 
 * John Carter      June 10 2017        v1.0.2	Clean the code by using macros
 * Jason Robinson   June 11 2017        v1.2.0	Major change: configure Timer1 
 *												and move the blinking LED to T1 ISR.
 *
 *****************************************************************************/

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include <libpic30.h>
#define LED         _LATA0
#define HALF_SEC    8000000
#define 	_ISR_NO_PSV 	__attribute__((__interrupt__, no_auto_psv))

void    _ISR_NO_PSV  _T1Interrupt(void){
        IFS0bits.T1IF = 0;
        LED ^= 1;
}

void TMR1_Initialize(void){
    TMR1 = 0x0000;
    PR1 = 0x0F43;
    T1CON = 0x8030;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
}
void main(void) {
    OSCILLATOR_Initialize();
    SYSTEM_Initialize();
    TMR1_Initialize();
    while(1);
}

