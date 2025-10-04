# MCU and Clock
MCU = atmega328p
F_CPU = 16000000UL

# Tools
CC = avr-gcc
OBJCOPY = avr-objcopy

# Flags
CFLAGS = -std=c11 -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -IInclude
LDFLAGS = -mmcu=$(MCU)

# Project
TARGET = main
SRC = src/main.c src/max7219.c
OBJ = $(SRC:.c=.o)

# Default build
all: $(TARGET).hex

# Compile .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Link .o → .elf
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Convert .elf → .hex
%.hex: %.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash to MCU
flash: $(TARGET).hex
	avrdude -c arduino -p m328p -P COM10 -b 115200 -U flash:w:$<

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).hex 
