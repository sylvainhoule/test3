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
 *
 *****************************************************************************/

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include <libpic30.h>

/*
 * 
 */
void main(void) {
    OSCILLATOR_Initialize();
    SYSTEM_Initialize();

    while(1){
        _LATA0 ^= 1;
        __delay32(8000000);
    }
}

