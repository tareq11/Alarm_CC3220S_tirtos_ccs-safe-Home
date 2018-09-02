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
#include <ti/devices/cc32xx/driverlib/timer.h>
/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>

/* Example/Board Header files */
#include "Board.h"
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Event.h>

#include <xdc/cfg/global.h>

//#include <xdc/std.h>
#include <xdc/runtime/system.h>
#include <stdio.h>
#include <stdlib.h>
#include "I2C_Utils.h"
#include "alarm.h"

/*
 *  ======== led_function ========
 */
#define TSL_SLAVE_ADDR 0x39
#define DATA_ADDRESS 0x8C


void * i2c_function2(void * args){
    sleep(2);
    return 0;
}

void * i2c_function(void * args)
{
    I2C_Handle i2c;
    I2C_Params i2cparams;
    uint8_t txData[20] = {0};
    uint8_t rxData[20] = {0};
    uint32_t channel0,channel1;
    uint32_t high,low;
    unsigned int lux,temp;
    char* text = "";

    I2C_Params_init(&i2cparams);

    i2cparams.bitRate = I2C_400kHz;

    i2c = I2C_open(Board_I2C0, &i2cparams);

    // power on command as instructed in datasheet.
    txData[0] = 0x00;
    txData[1] = 0x03;

    if(SensorI2C_WriteRead(TSL_SLAVE_ADDR, i2c, txData, 2, rxData, 1) != 1)
    {
        uart_function("I2C failed.\n");
        return 0;
    }

    if(rxData[0] != 0x03)
    {
        uart_function("TSL Power up failed.\n");
        return 0;
    }

    //sleeping 400ms to read data, as instructed in datasheet
    Task_sleep(400);

    //data address
    txData[0] = 0x8C;

    //read data from sensor
    while(1)
    {
        if(alarm_on == 0){
            SensorI2C_WriteRead(TSL_SLAVE_ADDR, i2c, txData, 1, rxData, 4);
            low = rxData[0];
            high = rxData[1];

            channel0 = 256 * high + low;

            low = rxData[2];
            high = rxData[3];

            channel1 = 256 * high + low;

            //convert channel0 and chammel1 to lux
            //lux = CalculateLux(0,0,channel0,channel1,1,&temp);
            if(channel0 > 2000){
                sprintf(text, "Lux measure: %d\nLight spike detected!\n", channel0);
                uart_function(text);
                alarm_on = 1;
            }
        }
        sleep(2);
    }
}




