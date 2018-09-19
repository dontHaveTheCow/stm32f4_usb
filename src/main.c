/*
 * STM32 and C libraries
 */

#include <stm32f4xx.h>
#include "defines.h"
#include "tm_stm32f4_usb_hid_device.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"

int main(void)
{
    uint8_t already = 0;
    
    /* Set structs for all examples */
    TM_USB_HIDDEVICE_Keyboard_t Keyboard;
    TM_USB_HIDDEVICE_Gamepad_t Gamepad1, Gamepad2;
    TM_USB_HIDDEVICE_Mouse_t Mouse;

	/* Initialize system */
	SystemInit();
	
	/* Initialize leds */
	TM_DISCO_LedInit();
	
	/* Initialize button */
	TM_DISCO_ButtonInit();
	
	/* Initialize delay */
	TM_DELAY_Init();
	
	/* Initialize USB HID Device */
	TM_USB_HIDDEVICE_Init();
    
	TM_USB_HIDDEVICE_KeyboardStructInit(&Keyboard);
	//TM_USB_HIDDEVICE_GamepadStructInit(&Gamepad1);

	TM_DISCO_LedToggle(LED_GREEN);	

    while (1) {          

        if (TM_USB_HIDDEVICE_GetStatus() == TM_USB_HIDDEVICE_Status_Connected) {
            TM_DISCO_LedOn(LED_GREEN);
			TM_DISCO_LedOff(LED_RED);
        }
        else {
            /* Turn off green LED */
            TM_DISCO_LedOff(LED_GREEN);
			TM_DISCO_LedOn(LED_RED);
        }
    }
}