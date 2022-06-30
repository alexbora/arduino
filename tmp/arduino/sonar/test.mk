MCU=atmega328p
F_CPU=16000000UL
CC=avr-g++
OBJCOPY=avr-objcopy
CFLAGS=-std=gnu++11 -Wall -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -g -Os -DARDUINO=10819 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -mmcu=${MCU} -DF_CPU=${F_CPU} -I. 
# CFLAGS+=-std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10819 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/root/.arduino15/packages/arduino/hardware/avr/1.8.5/cores/arduino -I/root/.arduino15/packages/arduino/hardware/avr/1.8.5/variants/standard -I/root/Arduino/libraries/NewPing/src 

TARGET=led
SRCS=led.c
all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS} -I./src -I/home/alex/tmp/arduino/sonar/arduino -I./standard core.a
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
flash:
	# avrdude -p ${MCU} -c arduino -U flash:w:${TARGET}.hex:i -F -P /dev/ttyUSB0 -b 115200
	avrdude -F -V -c arduino -p ${MCU} -P /dev/ttyUSB0 -b 115200 -U flash:w:${TARGET}.hex
clean:
	rm -f *.bin *.hex
