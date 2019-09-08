/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISAbits.TRISA4
#define SDO1_LAT                  LATAbits.LATA4
#define SDO1_PORT                 PORTAbits.RA4
#define SDO1_WPU                  WPUAbits.WPUA4
#define SDO1_OD                   ODCONAbits.ODCA4
#define SDO1_ANS                  ANSELAbits.ANSA4
#define SDO1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SDO1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SDO1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SDO1_GetValue()           PORTAbits.RA4
#define SDO1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISAbits.TRISA5
#define SDI1_LAT                  LATAbits.LATA5
#define SDI1_PORT                 PORTAbits.RA5
#define SDI1_WPU                  WPUAbits.WPUA5
#define SDI1_OD                   ODCONAbits.ODCA5
#define SDI1_ANS                  ANSELAbits.ANSA5
#define SDI1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SDI1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SDI1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SDI1_GetValue()           PORTAbits.RA5
#define SDI1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISBbits.TRISB6
#define SCK1_LAT                  LATBbits.LATB6
#define SCK1_PORT                 PORTBbits.RB6
#define SCK1_WPU                  WPUBbits.WPUB6
#define SCK1_OD                   ODCONBbits.ODCB6
#define SCK1_ANS                  ANSELBbits.ANSB6
#define SCK1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCK1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCK1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCK1_GetValue()           PORTBbits.RB6
#define SCK1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/