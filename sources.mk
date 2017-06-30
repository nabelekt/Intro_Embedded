#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************


# Platform Overrides
PLATFORM = HOST

SOURCE_PATH = src/

SRCS_ALL = $(SOURCE_PATH)main.c \
	$(SOURCE_PATH)memory.c \
	$(SOURCE_PATH)interrupts_msp432p401r_gcc.c \
	$(SOURCE_PATH)startup_msp432p401r_gcc.c \
	$(SOURCE_PATH)system_msp432p401r.c \
	$(SOURCE_PATH)course1.c \
	$(SOURCE_PATH)data.c \
	$(SOURCE_PATH)stats.c

ifeq ($(PLATFORM), HOST)
	SRCS = $(SOURCE_PATH)main.c \
	$(SOURCE_PATH)memory.c \
	$(SOURCE_PATH)course1.c \
	$(SOURCE_PATH)data.c \
	$(SOURCE_PATH)stats.c

	INCLUDES = -Iinclude/common

else
	SRCS = SRCS_ALL

	INCLUDES = -Iinclude/CMSIS \
	-Iinclude/common \
	-Iinclude/msp432

endif