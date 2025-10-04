#include <avr/io.h>
#include <util/delay.h>
#include "max7219.h"

// ======================= Pattern Definitions =======================
// Each row = 8 bits → 1 = LED ON, 0 = LED OFF

uint8_t smile[8] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b01000010,
    0b00111100};

uint8_t sad[8] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10011001,
    0b10100101,
    0b01000010,
    0b00111100};

uint8_t wink[8] = {
    0b00111100,
    0b01000010,
    0b10100001,
    0b10000001,
    0b10111101,
    0b10011001,
    0b01000010,
    0b00111100};

// ======================= Helper Function =======================
// Display an 8x8 pattern on the LED matrix
void display_pattern(uint8_t pattern[8])
{
    for (uint8_t row = 0; row < 8; row++)
    {
        max7219_setRow(row + 1, pattern[row]);
        // +1 because MAX7219 rows are 1–8 (not 0–7)
    }
}

// ======================= MAIN =======================
int main(void)
{
    max7219_init(); // initialize display

    while (1)
    {

        display_pattern(smile);
        _delay_ms(1000);

        display_pattern(sad);
        _delay_ms(1000);

        display_pattern(wink);
        _delay_ms(1000);
    }
}
