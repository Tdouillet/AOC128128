/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/system.h"
#include "DELAY.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/spi1.h"
#include "extra_fct.h"

/*
                         Main application
 */

uint8_t half[]={
    0x40, 0x5F, 0x00, 0x7F, 0x00, 0x00
};

uint8_t half_white[]={
    0x37, 0x7F, 0x00, 0x7F, 0xFF, 0xFF
};

uint8_t quart[]={
    0x60, 0x7F, 0x00, 0x7F, 0x00, 0x00
};

uint8_t three_quart[]={
    0x20, 0x3F, 0x00, 0x7F, 0x00, 0x00
};

uint8_t black[]={
    0x00, 0x7F, 0x00, 0x7F, 0x00, 0x00
};

uint8_t white[]= {
    0x00, 0x7F, 0x00, 0x7F, 0xFF, 0xFF
};

uint8_t red[]= {
    0x00, 0x7F, 0x00, 0x7F, 0xF8, 0x00
};

uint8_t green[]= {
    0x00, 0x7F, 0x00, 0x7F, 0x07, 0xE0
};

uint8_t blue[]= {
    0x00, 0x7F, 0x00, 0x7F, 0x00, 0x1F
};

uint8_t nom_t[]={
    
    0x04, 0x32, 0x03, 0x07, 0x7, 0x00, 0xFF, 
    5,5,5,5,5,6,5,6,6,6,5,6,5,5,5,5,5,6,5,5,5,5,6,6,6,6,5,6,6,6,5,6,6,6,5,6,5,6,6,6,6,6,5,5,5,5,5,
    6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,6,5,6,5,6,6,5,6,6,6,5,6,5,6,6,6,6,6,6,6,5,6,6,
    6,6,5,6,6,6,5,5,5,5,5,6,6,6,5,6,6,6,5,5,5,5,6,6,6,5,6,5,6,6,5,6,6,6,5,6,5,6,6,6,6,6,6,6,5,6,6,
    6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,5,5,5,5,5,6,5,6,6,6,5,6,5,6,6,6,6,6,6,6,5,6,6,
    6,6,5,6,6,6,5,6,6,6,5,6,5,5,5,5,5,6,5,5,5,5,6,6,5,6,6,6,5,6,6,5,5,5,6,6,5,5,5,5,5,6,6,6,5,6,6

};

uint8_t nom_y[]={
    
    0x04, 0x1A, 0x03, 0x07, 0x7, 0x00, 0xFF, 
    5,6,6,6,5,6,6,6,5,6,6,6,5,6,6,6,5,6,5,6,6,6,5,
    6,5,6,5,6,6,6,5,6,5,6,6,5,5,6,6,5,6,5,5,6,6,5,
    6,6,5,6,6,6,6,5,6,5,6,6,5,6,5,6,5,6,5,6,5,6,5,
    6,6,5,6,6,6,5,5,5,5,5,6,5,6,6,5,5,6,5,6,6,5,5,
    6,6,5,6,6,6,5,6,6,6,5,6,5,6,6,6,5,6,5,6,6,6,6
    
};

uint8_t nom_c[]={
    
    0x04, 0x1A, 0x03, 0x0A, 0x7, 0x00, 0xFF,
    6,6,6,6,6,6,6,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    6,6,6,6,6,6,6,5,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    6,5,5,5,6,6,6,5,5,5,6,6,5,6,6,6,5,6,5,5,5,5,5,
    5,6,6,6,5,6,5,6,6,6,5,6,5,5,6,5,5,6,5,6,6,6,6,
    5,6,6,6,6,6,5,6,6,6,5,6,5,6,5,6,5,6,5,5,5,5,6,
    5,6,6,6,5,6,5,6,6,6,5,6,5,6,6,6,5,6,5,6,6,6,6,
    6,5,5,5,6,6,6,5,5,5,6,6,5,6,6,6,5,6,5,5,5,5,5

};



//void Delay_us(unsigned int usec)
//{
//   while(usec > 0)
//   {
//       __delay_us(1);
//      usec--;
//    }
//}

void Delay(unsigned int msec)
{
   while(msec > 0)
   {
      __delay_ms(1);
      msec--;
    }
}

void RandomPlace(uint8_t tab[], uint16_t fill_color){
    
    uint8_t offsetx = tab[1]-tab[0];
    uint8_t offsety = tab[3]-tab[2];
    
    uint8_t x = rand()%(128-offsetx);
    uint8_t y = rand()%(128-offsety);
    
    WriteComm(0x15); 
    WriteData(x); 
    WriteData((x+offsetx));
    
    WriteComm(0x75); 
    WriteData(y); 
    WriteData((y+offsety));
        
    WriteComm(0x5C);
    
    uint32_t size = (offsetx+1)*(offsety+1);
    
    for (uint32_t i = 0; i<size;i++){
        
        WriteData(tab[tab[i+tab[4]]]);
        WriteData(tab[tab[i+tab[4]]]);
        
    }
    
    Delay(1000);
    
    for (uint32_t i = 0; i<= size;i++){
        WriteData(fill_color/256);
        WriteData(fill_color%256);
    }
    
}

void BP1_CallBack(void)
{
    DC_SetLow();
    RST_SetLow();
    
    Delay(300);
    
    /*Deactivate reset*/
    RST_SetHigh();
    //Set display off
    WriteComm(0xAE); 
    
    //Disable internal VDD regulator
    WriteComm(0xAB);
    WriteData(0x00);
    
    LED_SetHigh();
    Delay(2000);
    LED_SetLow();
    
    
}



int main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();
    
    BP1_SetInterruptHandler(BP1_CallBack);
    
    DC_SetLow();
    
    RST_SetHigh();

    
    /*Set SPI mode to 3 wire mode*/
    BS0_SetLow();
    BS1_SetLow();
    
    /*Activate reset*/
    RST_SetLow();
    
    Delay(300);
    
    /*Deactivate reset*/
    RST_SetHigh();
    
    /*Send initialization data to the screen*/
    Screen_SPI_Init();
    
    /*Activate VCC during delay
     LED to indicate time */
    LED_SetHigh();
    Delay(9000);
    LED_SetLow();
    Delay(300);
    
    WriteComm(0xAF);
    
    Delay(200);
    
    //WriteComm(0x5C);
        
    //Set beginning and end RAM address
    WriteComm(0x15); 
    WriteData(0x00); 
    WriteData(0x7F);
    
    WriteComm(0x75); 
    WriteData(0x00);
    WriteData(0x7F);
        
    WriteComm(0x5C);
        
    Fill(white);
    Delay(500);
    
    while (1)
    {
        
        Fill(quart);
        Delay(500);
        Fill(half);
        Delay(500);
        Fill(three_quart);
        Delay(500);
        Fill(black);
        Delay(500);
        Fill(white);
        Delay(500);
         
        RandomPlace(nom_y,WHITE);
        RandomPlace(nom_t,WHITE);
        RandomPlace(nom_c,WHITE);

        }

    return 1;
}
/**
 End of File
*/

