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

/* Example/Board Header files */
#include "Board.h"
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Event.h>

#include <xdc/cfg/global.h>

//#include <xdc/std.h>
#include <xdc/runtime/system.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void uart_function(char * text)
{
    UART_Handle uart_handle;
    UART_Params uart_params;

    //semaphore - pend
    Semaphore_pend(print_semaphore, BIOS_WAIT_FOREVER);

    UART_init();
    UART_Params_init(&uart_params);
    uart_params.readDataMode = UART_DATA_TEXT;
    uart_params.writeDataMode = UART_DATA_TEXT;
    uart_params.readReturnMode = UART_RETURN_FULL;
    uart_params.readEcho = UART_ECHO_OFF;
    uart_params.baudRate = 115200;

    uart_handle = UART_open(Board_UART0, &uart_params);

    if(uart_handle == NULL){
        printf("Error: opening UART failed.\n");
        return;
    }
    UART_write(uart_handle, text, strlen(text));
    UART_close(uart_handle);

    //semaphore - release
    Semaphore_post(print_semaphore);

}

