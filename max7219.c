//============================================================
// max7219.c - Driver code for MAX7219 LED Matrix
//============================================================

// First we include our header file so this file "knows"
// about the functions and pin definitions we made.
#include "max7219.h"

//============================================================
// Small helper: send one command + one data byte to MAX7219
//============================================================
void max7219_send(uint8_t addr, uint8_t data)
{
    // 1. Bring CS (chip select) LOW to tell MAX7219
    //    "Hey, I’m sending you something"
    PORTB &= ~(1 << max7219_CS);

    // 2. Send the address (command) byte
    SPDR = addr; // Put data in SPI Data Register
    while (!(SPSR & (1 << SPIF)))
        ; // Wait until transfer complete

    // 3. Send the data byte
    SPDR = data;
    while (!(SPSR & (1 << SPIF)))
        ; // Wait until transfer complete

    // 4. Bring CS HIGH to "latch" the data into MAX7219
    PORTB |= (1 << max7219_CS);
}

//============================================================
// Initialize the MAX7219 chip for 8x8 LED Matrix use
//============================================================
void max7219_init(void)
{
    // --- Configure SPI pins ---
    DDRB |= (1 << max7219_DIN) | (1 << max7219_CLK) | (1 << max7219_CS);

    // --- Enable SPI in Master Mode ---
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
    // SPE  = SPI Enable
    // MSTR = Master Mode
    // SPR0 = Clock speed (Fosc/16, good starting point)

    // --- Setup MAX7219 registers ---
    max7219_send(0x0C, 0x01); // Shutdown register: 0x01 = Normal Operation
    max7219_send(0x0B, 0x07); // Scan limit: display all 8 digits/rows
    max7219_send(0x09, 0x00); // Decode mode: 0x00 = raw matrix (no BCD decoding)
    max7219_send(0x0A, 0x08); // Intensity: medium brightness (0x00–0x0F)
    max7219_send(0x0F, 0x00); // Display test: off
    max7219_clear();          // Start with a blank screen
}

//============================================================
// Clear the display (all LEDs OFF)
//============================================================
void max7219_clear(void)
{
    for (uint8_t i = 1; i <= 8; i++)
    {
        max7219_send(i, 0x00); // Write 0 to each row
    }
}

//============================================================
// Set one row with an 8-bit pattern
// Example: row=1, value=0b10101010 → lights alternate LEDs
//============================================================
void max7219_setRow(uint8_t row, uint8_t value)
{
    if (row >= 1 && row <= 8) // Row must be between 1 and 8
    {
        max7219_send(row, value);
    }
}

//============================================================
// Print a character (placeholder for now)
//============================================================
void max7219_printChar(char c, uint8_t position)
{
    // Later we’ll make a font table like:
    // A = {0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00}
    // For now we’ll just clear that position.
    max7219_setRow(position, 0x00);
}
