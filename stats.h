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
 * @file stats.h
 * @brief Header file for Week 1 Application Assignment
 *
 * This application performs statistical analytics on a dataset.
 *
 * @author Thomas Nabelek
 * @date May 2017
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(unsigned char * data, unsigned int num_elements);
/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median
 *
 * This function takes an array of data and uses the other provided functions to calculate and then display the desired statistic
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return void
 */

void print_array(unsigned char *, unsigned int);
/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * N/A
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return void
 */

unsigned char find_median(unsigned char *, unsigned int);
/**
 * @brief Given an array of data and a length, returns the median value
 *
 * N/A
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return median : median of values in data
 */

unsigned char find_mean(unsigned char *, unsigned int);
/**
 * @brief Given an array of data and a length, returns the mean
 *
 * N/A
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return mean : mean of values in data
 */

unsigned char find_maximum(unsigned char *, unsigned int);
/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * N/A
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return max : maximum of values in data
 */

unsigned char find_minimum(unsigned char *, unsigned int);
/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * N/A
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return min : min of values in data
 */

void sort_array(unsigned char *, unsigned int);
/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * Returns the referenced array with the zeroth element as the largest value, and the last element (n-1) as the smallest value.
 *
 * @param data : array of data to be analyzed
 * @param nun_elements : the number of elements (or length) stored in data
 *
 * @return void
 */



#endif /* __STATS_H__ */
