######################################################################
# @author      : alex (alexbora@gmail.com)
# @file        : Makefile
# @created     : Miercuri Iun 22, 2022 20:10:01 EEST
######################################################################

FQBN := arduino:avr:pro
PORT := /dev/ttyUSB0
BUILD := build
FLAGS :=-Os

ARDUINO := arduino-cli

SKETCH := $(wildcard *.ino)
LIBS := $(wildcard *.cpp *.h *.tcc)
HEX := $(BUILD)/$(subst :,.,$(FQBN))/$(addsuffix .hex, $(SKETCH))


all: $(HEX)

$(HEX): $(SKETCH) $(LIBS)
	$(ARDUINO) compile -b $(FQBN) \
	--build-property compiler.cpp.extra_flags="$(FLAGS)" -e

upload: $(HEX)
	$(ARDUINO) upload -b $(FQBN) -p $(PORT) -i $(HEX)

