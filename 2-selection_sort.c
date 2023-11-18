#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * findIndex - function returns index
 * @arr: array
 * @size: the array size
 * @target: target
 * Return: int
 */

int findIndex(int arr[], int size, int target)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		if (arr[i] == target)
			return (i);
	}

	return (-1);
}

/**
 * small - function gets the samm value
 * @arr: array
 * @size: size
 * @target: target
 * Return: int
 */
int small(int *arr, size_t size, int target)
{
	int result = -1;
	size_t i;

	for (i = 0; i < size; ++i)
	{
		if (arr[i] < target && (result == -1 || arr[i] < result))
		{
			result = arr[i];
		}
	}
	return (result);
}

/**
 * selection_sort - function sorts array
 * @array: the array
 * @size: the size
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	int index, number, sm;

	if (array == NULL || size < 2)
		return;

	for (; i < size; i++)
	{
		number = array[i];
		sm = small(&array[i + 1], size - i - 1, number);
		if (sm != -1)
		{
			index = findIndex(array, size, sm);
			array[i] = sm;
			array[index] = number;
			print_array(array, size);
		}
	}
}
