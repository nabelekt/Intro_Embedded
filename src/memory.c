/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/***********************************************************
 Global Variables
***********************************************************/
char buffer[MAX_LENGTH];

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    uint8_t * temp = (uint8_t *) malloc(sizeof(uint8_t) * length);
    uint8_t * temp_position = temp;
    uint8_t * dst_position = dst;
    int i;

    for(i = 0; i < length; i++)
        *temp_position++ = *src++;
    temp_position = temp;
    for(i = 0; i < length; i++)
        *dst_position++ = *temp_position++;

    free(temp);

    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    uint8_t * dst_tmp = dst;
    for (int i = 0; i < length; i++)
        *dst_tmp++ = *src++;

    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {

    for (int i = 0; i < length; i++)
        *src++ = value;

    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {

    for (int i = 0; i < length; i++)
        *src++ = 0;

    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    uint8_t * dst = (uint8_t *) malloc(sizeof(uint8_t) * length);

    int i;
    for (i = 0; i < length; i++)
        dst[i] = src[length-1-i];

    my_memcopy(dst, src, length);
    free(dst);

    return src;
}

int32_t * reserve_words(size_t length) {
    return (int32_t *) malloc(length * (WORD_SIZE/8));
}

void free_words(uint32_t * src) {
    free(src);
}