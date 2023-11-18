#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0;
	int *count_array = NULL;
	int *output = NULL;
	size_t i;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++) {
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Allocate memory for the count_array */
	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	/* Initialize the count_array with 0s */
	for (i = 0; i <= (size_t)max_value; i++) {
		count_array[i] = 0;
	}

	/* Count the occurrences of each element */
	for (i = 0; i < size; i++) {
		count_array[array[i]]++;
	}

	/* Modify the count_array to store the actual positions */
	for (i = 1; i <= (size_t)max_value; i++) {
		count_array[i] += count_array[i - 1];
	}

	/* Allocate memory for the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		free(count_array);
		return;
	}

	/* Build the output array */
	for (i = size - 1; i < (size_t)-1; i--) {
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++) {
		array[i] = output[i];
	}

	/* Print the count_array */
	for (i = 0; i <= (size_t)max_value; i++) {
		printf("%d", count_array[i]);
		if (i != (size_t)max_value)
			printf(", ");
	}
	printf("\n");

	/* Free the allocated memory */
	free(count_array);
	free(output);
}
