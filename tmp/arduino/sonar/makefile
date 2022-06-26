
all: b 
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:blink_led.hex 

a: b
	# avr-g++ -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink_led.o led.c
	# avr-gcc -mmcu=atmega328p blink_led.o -o blink_led                                           4s 19:05:14
	avr-objcopy -O ihex -R .eeprom blink_led blink_led.hex 
	# avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:blink_led.hex 
	
b:  
	avr-g++ -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink_led led.c


# ~/tmp/arduino/sonar ❯ avr-g++ -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink_led.o led.c                        19:28:10
# ~/tmp/arduino/sonar ❯ avr-gcc -mmcu=atmega328p blink_led.o -o blink_led                                              19:28:17
# ~/tmp/arduino/sonar ❯ avr-objcopy -O ihex -R .eeprom blink_led blink_led.hex                                         19:28:24
# ~/tmp/arduino/sonar ❯ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:blink_led.hex
