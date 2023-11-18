#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_compare - Compares two elements based on the direction and swaps them if necessary.
 * @array: The array.
 * @size: The size of the array.
 * @i: The first element index.
 * @j: The second element index.
 * @dir: The direction (1 for ascending, 0 for descending).
 */
void bitonic_compare(int *array, size_t size, size_t i, size_t j, int dir)
{
	if (dir == (array[i] > array[j]))
	{
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges two subarrays in the given direction.
 * @array: The array.
 * @size: The size of the array.
 * @low: The starting index of the first subarray.
 * @count: The number of elements to be merged.
 * @dir: The direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
			bitonic_compare(array, size, i, i + k, dir);

		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive function to perform bitonic sort on a subarray.
 * @array: The array.
 * @size: The size of the array.
 * @low: The starting index of the subarray.
 * @count: The number of elements in the subarray.
 * @dir: The direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		bitonic_sort_recursive(array, size, low, k, 1);
		bitonic_sort_recursive(array, size, low + k, k, 0);

		bitonic_merge(array, size, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	bitonic_sort_recursive(array, size, 0, size, 1);
}
