
#include "dev_config.h"
#include <fcntl.h>




//int DEV_RST_PIN=18;
//int DEV_CS_PIN=22;
//int DEV_DRDY_PIN=17;


void DEV_Digital_Write(UWORD Pin, UBYTE Value)
{
    digitalWrite(Pin, Value);
}

UBYTE DEV_Digital_Read(UWORD Pin)
{
    UBYTE Read_value = 0;
    Read_value = digitalRead(Pin);
    return Read_value;
}


UBYTE DEV_SPI_WriteByte(uint8_t Value)
{
    UBYTE temp = 0;
    wiringPiSPIDataRW(0, &Value, 1);
    temp = Value;
    return temp;
}

UBYTE DEV_SPI_ReadByte(void)
{
    return DEV_SPI_WriteByte(0x00);
}


void DEV_Delay_ms(UDOUBLE xms)
{
    delay(xms);
}


UBYTE DEV_Module_Init(void)
{
    wiringPiSPISetupMode(0, 1000000, 1);
    return 0;}


void DEV_Module_Exit(void)
{
    DEV_Digital_Write(DEV_RST_PIN, 0);
    DEV_Digital_Write(DEV_CS_PIN, 0);
}
