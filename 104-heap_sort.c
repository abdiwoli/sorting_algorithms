#include <stdio.h>
#include "sort.h"

/**
 * sift_down - Performs the sift-down operation on a heap.
 * @array: The array representing the heap.
 * @start: The index of the node to sift down.
 * @end: The index of the last node in the heap.
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap;
	int temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);

		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size <= 1)
		return;

	for (i = size / 2 - 1; (int)i >= 0; i--)
		sift_down(array, i, size - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
