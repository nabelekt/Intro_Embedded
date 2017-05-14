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
 * @file stats.c
 * @brief Program file for Week 1 Application Assignment
 *
 * This application performs statistical analytics on a dataset.
 *
 * @author Thomas Nabelek
 * @date May 2017
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_statistics(test, SIZE);

}

void print_statistics(unsigned char * data, unsigned int num_elements) {

	printf("\nData to be analyzed:\n");
	print_array(data, num_elements);

	sort_array(data, num_elements);

	printf("Sorted data:\n");
	print_array(data, num_elements);


}

void print_array(unsigned char * data, unsigned int num_elements) {
	
	printf("   ");
	// Iterate through data array and print each element with new line after every 10 elements
	for (int i = 0; i < num_elements; i++) {
		printf("%5d ", data[i]);
		if (i % 10 == 9)
			printf("\n   ");
	}

	printf("\n");

}


unsigned char find_median(unsigned char * data, unsigned int num_elements) {
	


}


// unsigned char find_mean(unsigned char * data, unsigned int num_elements) {
	
// }


// unsigned char find_maximum(unsigned char * data, unsigned int num_elements) {
	
// }


// unsigned char find_minimum(unsigned char * data, unsigned int num_elements) {
	
// }


void sort_array(unsigned char * data, unsigned int num_elements) {

	// Use selection sort
	for (int i = 0; i < num_elements - 1; i++) {
		int min_ind = i; // Assume current value is minimum

		// Search array past current value
		for (int j = i + 1; j < num_elements; j++) {
			if (data[j] < data[min_ind])
				min_ind = j;
		}

		// If new minimum is found, swap with current minimum
		if (min_ind != i) { // If 
			unsigned char temp = data[i];
			data[i] = data[min_ind];
			data[min_ind] = temp;
		}
	}
	
}
