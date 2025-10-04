#ifndef max7219_h
#define max7219_h

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

//=====================SPI Pin Definations====================
// These can be changed later if we want different configurations
#define max7219_DIN PB3 // MOSI (Arduino UNO: pin 11) Data
#define max7219_CLK PB5 // SCL (Arduino UNO: pin 13) serial clock
#define max7219_CS PB2  // CS (Arduino UNO: pin 10) chip/slave select

// We will be declaring functions so these can later be used in the "main.c"
// 1.
void max7219_send(uint8_t addr, uint8_t data);
// this function send command to MAX7219CMG IC using SPI interface
//  Eg: max7219_send(0x0A, 0x05);
// 0x0A is a command to address the light intensitiy of the grid.
// 0x05 is the data, that set the light intensity to "9/32" = 28 %.

// 2.
void max7219_init(void);
// initilize the MAX7219 for matrix use.

// 3.
void max7219_clear(void);
// clear the display.

// 4.
void max7219_setRow(uint8_t row, uint8_t value);
// Set row with 8 bit pattern.

// 5.
void max7219_printChar(char c, uint8_t position);
// print character at a position.

#endif