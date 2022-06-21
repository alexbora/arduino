######################################################################
# @author      : alex (alex@T400)
# @file        : Makefile
# @created     : marți iun 21, 2022 19:27:33 EEST
############


CC=/mnt/500x/e/bin/./arduino-cli

all:
	$(CC) upload -p /dev/ttyUSB0 -b arduino:avr:uno $1
	$(CC) compile -b arduino:avr:uno $1
