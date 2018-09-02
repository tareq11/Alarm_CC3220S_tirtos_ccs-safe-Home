/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== gpiointerrupt.c ========
 */
#include <stdint.h>
#include <stddef.h>
#include "unistd.h"
#include <ti/devices/cc32xx/inc/hw_types.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>
#include <ti/display/Display.h>
#include <ti/drivers/Timer.h>
/* Example/Board Header files */
#include "Board.h"
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Event.h>

#include <xdc/cfg/global.h>

//#include <xdc/std.h>
#include <xdc/runtime/system.h>
#include <stdio.h>
#include <stdlib.h>
//#include ADCs
#include <ti/drivers/ADC.h>
#include "alarm.h"
//#include displays
//#include <ti/display/Display.h>

//static Display_Handle display;

/* ADC conversion result variables */
uint16_t adcValue0;
uint32_t adcValue0MicroVolt;

void * ADCTask_func(void * args)
{

//    Display_init();


/*  // Open the display for output
    display = Display_open(Display_Type_UART, NULL);
    if (display == NULL) {
         Failed to open display driver
        printf("Error initializing Display.\n");
        return 0;
    }
    */
    ADC_Handle   adc;
    ADC_Params   params;
    int_fast16_t res;
    char* text = "ball measured\n";

    ADC_Params_init(&params);
    adc = ADC_open(Board_ADC0, &params);

    if (adc == NULL) {
        //Display_printf(display, 0, 0, "Error initializing ADC channel 1\n");
        printf("Error initializing ADC\n");
        return 0;
    }

    //Display_printf(display, 0, 0, "Waiting 60 seconds for initialization...\n");
    uart_function("Waiting 120 seconds for initialization...\n");
    sleep(30);
    uart_function("Waiting 90 seconds for initialization...\n");
    sleep(30);
    uart_function("Waiting 60 seconds for initialization...\n");
    sleep(30);
    uart_function("Waiting 30 seconds for initialization...\n");
    sleep(30);
    //Display_printf(display, 0, 0, "Testing started!\n");
    uart_function("Alarm started!\n");
    while(1){
        if(alarm_on == 0){
            res = ADC_convert(adc, &adcValue0);

            if (res == ADC_STATUS_SUCCESS) {

                adcValue0MicroVolt = ADC_convertRawToMicroVolts(adc, adcValue0);
                adcValue0MicroVolt /= 423;

                //Display_printf(display, 0, 0, "ADC channel 1 convert result (%d): %d uV\n", i,
                //               adcValue0MicroVolt/423);

                if(adcValue0MicroVolt > 2800){
                    sprintf(text,"ADC convert result: %d uV\nHuman Detected!!!\n", adcValue0MicroVolt);
                    uart_function(text);
                    alarm_on = 1;
                }
            }
            /*
            else {
                //Display_printf(display, 0, 0, "ADC channel 1 convert failed (%d)\n", i);
                printf("ADC convert failed (%d)\n", i);
            }
            */
        }
        sleep(2.5);
    }
}


