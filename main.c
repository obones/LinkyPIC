/*
 LinkyPIC - The embedded program to talk with a Linky Utility meter, for a PIC16F18446

 The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License");
 you may not use this file except in compliance with the License. You may obtain a copy of the
 License at http://www.mozilla.org/MPL/

 Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 ANY KIND, either express or implied. See the License for the specific language governing rights
 and limitations under the License.

 The Original Code is main.c.

 The Initial Developer of the Original Code is Olivier Sannier.
 Portions created by Olivier Sannier are Copyright (C) of Olivier Sannier. All rights reserved.
*/
#include "mcc_generated_files/mcc.h"
#include "tcp_server.h"

#define LED_On() LED_SetLow()
#define LED_Off() LED_SetHigh()

typedef enum {nlmError, nlmSynchronized} _NotificationLEDMode;
static volatile _NotificationLEDMode NotificationLEDMode = nlmError;

void NotificationLEDHandler(void)
{
    static volatile uint8_t Counter = 0;
    
    switch (Counter++)
    {
        case 0:
            LED_On();
            break;
        case 1:
            LED_Off();
            break;
        case 9:
            if (NotificationLEDMode == nlmError)
                Counter = 0;
            break;
        case 29:
            Counter = 0;
            break;
    }
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    TMR2_SetInterruptHandler(NotificationLEDHandler);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        Network_Manage();
        
        TCP_Server();
    }
}
/**
 End of File
*/