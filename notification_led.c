#include "mcc_generated_files/mcc.h"
#include "notification_led.h"

#define LED_On() LED_SetLow()
#define LED_Off() LED_SetHigh()

static volatile _NotificationLEDMode NotificationLEDMode = nlmError;

void SetNotificationLEDMode(_NotificationLEDMode mode) {
    NotificationLEDMode = mode;
}

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


