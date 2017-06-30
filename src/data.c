#include "data.h"
#include "memory.h"
#include <stdio.h>
#include <math.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t str_len = 0;

  ptr[str_len++] = '\0';

  int negative_flag = 0;
  if (data < 0) {
    negative_flag = 1;
    data = -data;
  }

  while(data != 0) {
    if (data % base <= 9)
      ptr[str_len++] = data % base + 48;
    else
      ptr[str_len++] = data % base + 97;

    data = data / base;
  }

  if (negative_flag)
    ptr[str_len++] = 45;

  my_reverse(ptr, str_len);

  return str_len;
}

/**
 * @brief Sets a value of a data array 
 *
 * Does ASCII-to-Integer conversion to convert data back from an ASCII represented
 * string into an integer type.  All operations are performed using pointer
 * arithmetic, not array indexing. The character string to convert is passed in as 
 * a uint8_t * pointer (ptr). The number of digits in the character set is passed
 * in as a uint8_t integer (digits). Supports bases 2 to 16. The converted 32-bit
 * signed integer is returned.  Handles signed data.  Does not use any string
 * functions or libraries

 * @param ptr - pointer to string
 * @param digits - number of digits in the string
 * @param base - base to convert to
 *
 * @return value of int
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int negative_flag = 0;
  int32_t value = 0;
  
  if (*ptr == 45) {
    negative_flag = 1;
    digits--;
    ptr++;
  }

  while (digits > 1) { // Stop at 1 for null terminator
    if (*ptr >= 48 && *ptr <= 57)
      value += (*ptr - 48) * pow(base, digits-2);
    else if (*ptr >= 97 && *ptr <= 102)
      value += *ptr - 97 * pow(base, digits-2);

    digits--;
    ptr++;
  }

  if (negative_flag)
    value = value * -1;

  return value;
}