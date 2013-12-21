/*******************************************************************************
  Generated Pin Manager File 

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI. 
    Generation Information : 
        Product Revision  :  MPLAB� Code Configurator - v1.0
        Device            :  PIC16F1825
        Version           :  1.1
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.21
        MPLAB             :  MPLAB X 1.90
*******************************************************************************/

/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/


#include <xc.h>
#include "pin_manager.h"

extern int sense;

/****************************************************************************
 *
 * Prototype:		void PIN_MANAGER_initializer(void)
 * Input:	    	none
 * Output:	    	none
 * Description:    	GPIO and peripheral I/O initialization
 * Usage:          	PIN_MANAGER_initializer();
 *
 ***************************************************************************/

void PIN_MANAGER_Initializer(void)
{
    LATA = 0x00;    
    TRISA = 0x3F;    
    ANSELA = 0x13;
    WPUA = 0x00;

    LATC = 0x00;    
    TRISC = 0x3C;    
    ANSELC = 0x0C;
    WPUC = 0x00;

    IOCAP = 0x04;

    IOCAN = 0x00;

    IOCAF = 0x00;

    APFCON0 = 0x00;

    APFCON1 = 0x00;
}

void PIN_MANAGER_IOC(void) 
{
    if (IOCAFbits.IOCAF2 == 1)
    {
	sense++;

        // Clear Interrupt Flag.
        IOCAFbits.IOCAF2 = 0;
    }
}
