This is a library developed by Rahul Gupta. I have decided to make it open source, i.e. the allow the user to copy/circulate this library at will.



this library is designed to control 8x8 LED matrix works on max7219 multiplexer IC.



It has some basic features:

// 1.

void max7219\_send(uint8\_t addr, uint8\_t data);

// this function send command to MAX7219CMG IC using SPI interface

//  Eg: max7219\_send(0x0A, 0x05);

// 0x0A is a command to address the light intensitiy of the grid.

// 0x05 is the data, that set the light intensity to "9/32" = 28 %.



// 2.

void max7219\_init(void);

// initilize the MAX7219 for matrix use.



// 3.

void max7219\_clear(void);

// clear the display.



// 4.

void max7219\_setRow(uint8\_t row, uint8\_t value);

// Set row with 8 bit pattern.



// 5.

void max7219\_printChar(char c, uint8\_t position);

// print character at a position.



**HOW IT PROGRAMM ?**
Simply create a folder (Eg: led matrix)
make 2 sub folders (named: Include and src)
in "Include" folder, copy "max7219.h".

in "src" folder, copy "max7219.c" along with your "main.c" code.



open cmd.

&nbsp;  |

&nbsp; ```

change directory to: your folder (eg: "led matrix")

&nbsp;  |

&nbsp; ```

type:-  make

&nbsp;  |

&nbsp; ```

type:-	make flash





**HOW TO CONFIGURE ?**

simply open device manager on your PC and check for the "COM PORT" at which your device is connected.

go makefile and change the COM PORT to the port that your device is connected to. 

