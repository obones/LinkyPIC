/*
 LinkyPIC - The embedded program to talk with a Linky Utility meter, for a PIC16F18446

 The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License");
 you may not use this file except in compliance with the License. You may obtain a copy of the
 License at http://www.mozilla.org/MPL/

 Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 ANY KIND, either express or implied. See the License for the specific language governing rights
 and limitations under the License.

 The Original Code is notification_led.h.

 The Initial Developer of the Original Code is Olivier Sannier.
 Portions created by Olivier Sannier are Copyright (C) of Olivier Sannier. All rights reserved.
*/
#ifndef NOTIFICATION_LED_H
#define	NOTIFICATION_LED_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum {nlmError, nlmSynchronized} _NotificationLEDMode;

void SetNotificationLEDMode(_NotificationLEDMode mode);

void NotificationLEDHandler(void);

#ifdef	__cplusplus
}
#endif

#endif	/* NOTIFICATION_LED_H */

