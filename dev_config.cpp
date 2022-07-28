
#include "dev_config.h"
#include <fcntl.h>




int DEV_RST_PIN=22;
int DEV_CS_PIN=7;
int DEV_DRDY_PIN=17;


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
    wiringPiSetupGpio();
    DEV_GPIO_Init();
    wiringPiSPISetupMode(0, 1000000, 1);
    return 0;}


void DEV_Module_Exit(void)
{
    DEV_Digital_Write(DEV_RST_PIN, 0);
    DEV_Digital_Write(DEV_CS_PIN, 0);
}

void DEV_GPIO_Init(void)
{

//    DEV_RST_PIN     = 18;
//        DEV_CS_PIN      = 22;
//        DEV_DRDY_PIN    = 17;

    DEV_GPIO_Mode(DEV_RST_PIN, 1);
    DEV_GPIO_Mode(DEV_CS_PIN, 1);
    DEV_GPIO_Mode(DEV_DRDY_PIN, 0);

    DEV_Digital_Write(DEV_CS_PIN, 1);
}

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode)
{

    if(Mode == 0 || Mode == INPUT) {
        pinMode(Pin, INPUT);
        pullUpDnControl(Pin, PUD_UP);
    } else {
        pinMode(Pin, OUTPUT);
    }

}
