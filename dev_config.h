#ifndef DEV_CONFIG_H
#define DEV_CONFIG_H

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include <mainwindow.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>


#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t


//extern int DEV_RST_PIN;
//extern int DEV_CS_PIN;
//extern int DEV_DRDY_PIN;

#define DEV_RST_PIN 18
#define DEV_CS_PIN 22
#define DEV_DRDY_PIN 17

/*------------------------------------------------------------------------------------------------------*/
void DEV_Digital_Write(UWORD Pin, UBYTE Value);
UBYTE DEV_Digital_Read(UWORD Pin);

UBYTE DEV_SPI_WriteByte(UBYTE Value);
UBYTE DEV_SPI_ReadByte(void);

UBYTE DEV_Module_Init(void);
void DEV_Module_Exit(void);

void DEV_Delay_ms(UDOUBLE xms);

#endif // DEV_CONFIG_H
