#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: The array to be sorted.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc((left_size + right_size) * sizeof(int));

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < left_size)
		merged[k++] = left[i++];

	while (j < right_size)
		merged[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = merged[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);

	merge(array, array, mid, array + mid, size - mid);
}
