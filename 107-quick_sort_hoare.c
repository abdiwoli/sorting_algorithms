#include "sort.h"



/**
 * custom_partition - sorts a partition of data in relation to a pivot
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int custom_partition(int *array, int min, int max, size_t size)
{
	int i, j, pivot = array[max], tmp;

	for (i = min, j = max; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * custom_quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: No Return
 */
void custom_quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = custom_partition(array, min, max, size);
		custom_quicksort(array, min, p - 1, size);
		custom_quicksort(array, p, max, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Hoare partition scheme
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	custom_quicksort(array, 0, size - 1, size);
}
