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
 *
 *****************************************************************************/

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include <libpic30.h>
#define LED         _LATA0
#define HALF_SEC    8000000

void main(void) {
    OSCILLATOR_Initialize();
    SYSTEM_Initialize();

    while(1){
        LED ^= 1;
        __delay32(HALF_SEC);
    }
}

