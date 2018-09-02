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
#include <ti/drivers/PWM.h>
#include "alarm.h"

//to display the value on the screen
//static Display_Handle display;

static PWM_Handle pwm;

void * PWM_function(void * args)
{
    PWM_Params params;
    uint16_t period = 3000;
    uint16_t duty = 0;
    uint16_t duty_inc = 50;

    PWM_Params_init(&params);
    params.periodUnits = PWM_PERIOD_US;
    params.periodValue = period;
    params.dutyUnits = PWM_DUTY_US;
    params.dutyValue = duty;

    pwm = PWM_open(Board_PWM0, &params);
    if(pwm == NULL){
        printf("Error opening PWM");
        return 0;
    }

    PWM_start(pwm);

    while(1){
        if(alarm_on == 1){
            duty += duty_inc;
            PWM_setDuty(pwm, duty);

            if((duty >= period) || (duty <= 0)){
                duty_inc *= -1;
            }
        }
        else if(alarm_on == 0){
            PWM_setDuty(pwm, 0);
        }
        usleep(5000);
    }
}

