/*
 * File:   extra_fct.c
 * Author: t.douillet
 *
 * Created on August 5, 2024, 2:30 PM
 */


#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/system.h"
#include "extra_fct.h"
#include <stdio.h>
#include <stdlib.h>

void WriteComm(uint8_t byte)
{
    CS_SetLow();
    DC_SetLow();
    SPI1_Exchange8bit(byte);
    CS_SetHigh();
}

void WriteData(uint8_t byte)
{
    CS_SetLow();
    DC_SetHigh();
    SPI1_Exchange8bit(byte);
    CS_SetHigh();
}

void Fill(uint8_t tab[]){
    
    WriteComm(0x15); 
    WriteData(tab[0]); 
    WriteData(tab[1]);
    
    WriteComm(0x75); 
    WriteData(tab[2]);
    WriteData(tab[3]);
        
    WriteComm(0x5C);
    
    uint32_t size = (tab[1]-tab[0]+1)*(tab[3]-tab[2]+1);
    
    for (uint32_t i = 0; i<= size;i++){
        WriteData(tab[4]);
        WriteData(tab[5]);
    }
    
}

void ColorTab2(uint8_t tab[]){
    
    WriteComm(0x15); 
    WriteData(tab[0]); 
    WriteData(tab[1]);
    
    WriteComm(0x75); 
    WriteData(tab[2]);
    WriteData(tab[3]);
        
    WriteComm(0x5C);
    
    uint32_t size = (tab[1]-tab[0]+1)*(tab[3]-tab[2]+1);
    
    for (uint32_t i = 0; i<size;i++){
        
        WriteData(tab[tab[i+tab[4]]]);
        WriteData(tab[tab[i+tab[4]]]);
        
    }
    
}

void ClearTab(uint8_t tab[]){
    
    WriteComm(0x15); 
    WriteData(tab[0]); 
    WriteData(tab[1]);
    
    WriteComm(0x75); 
    WriteData(tab[2]);
    WriteData(tab[3]);
        
    WriteComm(0x5C);
    
    uint32_t size = (tab[1]-tab[0]+1)*(tab[3]-tab[2]+1);
    
    for (uint32_t i = 0; i<= size;i++){
        WriteData(0xFF);
        WriteData(0xFF);
    }
    
}

void Screen_SPI_Init(void){
    
    //Unlock commands
    WriteComm(0xFD);
    WriteData(0x12); 
    
    WriteComm(0xFD);
    WriteData(0xB1);
    
    //Display on
    WriteComm(0xAE); 
    
    //Color Depth
    WriteComm(0xA0); 
    WriteData(0x66);
    
    //Set Line
    WriteComm(0xA1); 
    WriteData(0x00); 
    
    //Set offset
    WriteComm(0xA2);
    WriteData(0x00);
    
    //Reset display mode
    WriteComm(0xA6);
    
    //Enable internal VDD regulator
    WriteComm(0xAB); 
    WriteData(0x01); 
    
    //Set phase length
    WriteComm(0xB1);
    WriteData(0x32); 
    
    //Display enhancement
    WriteComm(0xB2); 
    WriteData(0xA4);
    WriteData(0x00);
    WriteData(0x00);
    
    //Set clock
    WriteComm(0xB3); 
    WriteData(0xF1);
    
    
    //Set segment low voltage
    WriteComm(0xB4); 
    WriteData(0xA0);
    WriteData(0xB5); 
    WriteData(0x55);
    
    //SetGPIO
    WriteComm(0xB5); 
    WriteData(0x00);
    
    //Set second pre-charge
    WriteComm(0xB6);
    WriteData(0x01);
    
    //Set Gamma LUT
    WriteComm(0xB8); 
    WriteData(0x02); 
    WriteData(0x03); 
    WriteData(0x04); 
    WriteData(0x05); 
    WriteData(0x06); 
    WriteData(0x07);
    WriteData(0x08);
    WriteData(0x09); 
    WriteData(0x0A); 
    WriteData(0x0B); 
    WriteData(0x0C); 
    WriteData(0x0D); 
    WriteData(0x0E); 
    WriteData(0x0F); 
    WriteData(0x10); 
    WriteData(0x11); 
    WriteData(0x12); 
    WriteData(0x13);
    WriteData(0x15);
    WriteData(0x17);
    WriteData(0x19);
    WriteData(0x1B);
    WriteData(0x1D); 
    WriteData(0x1F); 
    WriteData(0x21);
    WriteData(0x23); 
    WriteData(0x25); 
    WriteData(0x27);
    WriteData(0x2A);
    WriteData(0x2D);
    WriteData(0x30);
    WriteData(0x33);
    WriteData(0x36);
    WriteData(0x39);
    WriteData(0x3C);
    WriteData(0x3F);
    WriteData(0x42);
    WriteData(0x45);
    WriteData(0x48); 
    WriteData(0x4C);
    WriteData(0x50);
    WriteData(0x54);
    WriteData(0x58);
    WriteData(0x5C);
    WriteData(0x60);
    WriteData(0x64);
    WriteData(0x68);
    WriteData(0x6C);
    WriteData(0x70);
    WriteData(0x74);
    WriteData(0x78);
    WriteData(0x7D);
    WriteData(0x82);
    WriteData(0x87);
    WriteData(0x8C);
    WriteData(0x91);
    WriteData(0x96);
    WriteData(0x9B);
    WriteData(0xA0);
    WriteData(0xA5);
    WriteData(0xAA);
    WriteData(0xAF);
    WriteData(0xB4);
    
    //Set pre-charge voltage
    WriteComm(0xBB);
    WriteData(0x17);
       
    //Set VCOMH Select level
    WriteComm(0xBE);
    WriteData(0x05);
    
    //Set contrast for B G R
    WriteComm(0xC1);
    WriteData(0xC8); 
    WriteData(0x80); 
    WriteData(0xC8); 
    
    //Master contrast current control
    WriteComm(0xC7); 
    WriteData(0x0F); 
    
    //Set MUX ratio
    WriteComm(0xCA); 
    WriteData(0x7F); 
    
}
