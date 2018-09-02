/*
 * I2C_Utils.c
 */

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "unistd.h"

#include <ti/drivers/I2C.h>


uint8_t SensorI2C_WriteRead(uint8_t slave_address, I2C_Handle i2cHandle,
                            uint8_t *writeData, uint8_t writeLen,
                            uint8_t *readData, uint8_t readLen){

    I2C_Transaction master_transaction;
    //set write
    master_transaction.writeCount = writeLen;
    master_transaction.writeBuf = writeData;
    //set read
    master_transaction.readCount = readLen;
    master_transaction.readBuf = readData;
    //set slave address
    master_transaction.slaveAddress = slave_address;

    return I2C_transfer(i2cHandle, &master_transaction);

}
