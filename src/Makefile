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

#------------------------------------------------------------------------------
# This is a build system able to compile generate preprocessed output for
# c-source files, generate assembly output for c-source files, generate (but not
# link) the object file for c-source files, compile (but not link) all object
# files, compile all object files and link into a final executable, or clean
# files
#
# Thomas Nabelek, May 2017
#
# Useage: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#		%.i
# 		Generate preprocessed output for c-source files
#
#		%.asm
# 		Generate assembly output for c-source files
#
#		%.o
#			Generate the object file for c-source files but do not link
#
#		%.d
#			Generate the dependency file for a given c-source file
#
#		compile-all:
#			Compile all object files, but do not link
#
#		build:
#			Compile all object files and link into a final executable
#
#		clean:
#			Remove older files
#
# Platform Overrides:
#      Specify PLATFORM=HOST or PLATFORM=MSP432
#
#
#
#------------------------------------------------------------------------------
include sources.mk

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
	CC = gcc
	TARGET_FLAGS = -DHOST
	
	SRCS = main.c memory.c
	O_FILES = $(SRCS:.c=.o)
	DEP_FILES = $(SRCS:.c=.d)
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -T $(LINKER_FILE)
	TARGET_FLAGS = -DMSP432

	# Architectures Specific Flags (ARM only)
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	PLATFORM_FLAGS = -march=$(ARCH) -mcpu=$(CPU) --specs=$(SPECS) \
		-mthumb \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16

	SRCS = main.c memory.c system_msp432p401r.c startup_msp432p401r_gcc.c interrupts_msp432p401r_gcc.c
	O_FILES = $(SRCS:.c=.o)
	DEP_FILES = $(SRCS:.c=.d)
endif

O_FILES_ALL = $(SRCS_ALL:.c=.o)
MAP_FILES = $(SRCS_ALL:.c=.map)
OUT_FILES = $(SRCS_ALL:.c=.out)
ASM_FILES = $(SRCS_ALL:.c=.asm)
I_FILES = $(SRCS_ALL:.c=.i)
DEP_FILES_ALL = $(SRCS_ALL:.c=.d)

# General Flags
CPPFLAGS = $(TARGET_FLAGS)
CFLAGS = -Wall -Werror -g -O0 -std=c99 $(CPPFLAGS) $(INCLUDES)

# Targets
# Generate preprocessed output for c-source files
%.i: %.c
	$(CC) -E $(CFLAGS) $(PLATFORM_FLAGS) $< -o $@

# Generate assembly output for c-source files
%.asm: %.c
	$(CC) -S $(CFLAGS) $(PLATFORM_FLAGS) $< -o $@

# Generate the object file for c-source files but do not link
%.o: %.c
	$(CC) -c $(CFLAGS) $(PLATFORM_FLAGS) $< -o $@

# Generate the dependency file for a given c-source file
%.d: %.c
	$(CC) -c $(CFLAGS) $(PLATFORM_FLAGS) -M $< > $@

# Compile all object files, but do not link
.PHONY: compile-all
compile-all: clean $(O_FILES)

# Compile all object files and link into a final executable
.PHONY: build
build: clean $(DEP_FILES) $(O_FILES)
	$(CC) $(CFLAGS) $(PLATFORM_FLAGS) $(LDFLAGS) -Wl,-Map,c1m2.map $(O_FILES) -o c1m2.out
	size c1m2.out

.PHONY: clean
clean:
	rm $(O_FILES_ALL) $(MAP_FILES) $(OUT_FILES) $(ASM_FILES) $(I_FILES) $(DEP_FILES_ALL) c1m2.map c1m2.out -f
