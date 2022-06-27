MCU=atmega328p
F_CPU=16000000UL
CC=avr-g++
OBJCOPY=avr-objcopy
CFLAGS=-std=c++11 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=led
SRCS=led.c
all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS} 
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
flash:
	avrdude -p ${MCU} -c arduino -U flash:w:${TARGET}.hex:i -F -P /dev/ttyUSB0
clean:
	rm -f *.bin *.hex
