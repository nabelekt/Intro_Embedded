#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Does Integer-to-ASCII conversion from a standard integer type into an ASCII
 * string. All operations are performed using pointer arithmetic, not array
 * indexing. The number to convert is passed in as a signed 32-bit integer.
 * Supports bases 2 to 16 by specifying the integer value of the base you wish 
 * to convert to (base). Copies the converted character string to the uint8_t*
 * pointer passed in as a parameter (ptr). The signed 32-bit number will have 
 * a maximum string size (Hint: Think base 2). Returns the length of the converted
 * data (including a negative sign).  Places a null terminator at the end of the
 * converted c-string. Example my_itoa(1234, ptr, 10) returns an ASCII string
 * length of 4 or 5 if you include a null terminator.  Handles signed data.
 * Does not use any string functions or libraries

 * @param data - value to convert to string
 * @param ptr - pointer to string
 * @param base - base to convert to
 *
 * @return string length
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

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
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
