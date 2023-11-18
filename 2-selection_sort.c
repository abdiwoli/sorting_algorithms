#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


int findIndex(int arr[], int size, int target)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		if (arr[i] == target)
			return i;
	}

	return -1; 
}

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
	return result;
}

void selection_sort(int *array, size_t size)
{
    size_t i = 0;
    int index, number, sm;
 
    for (; i < size; i++)
    {
        number = array[i];
        sm = small(&array[i + 1], size - i -1, number);
        if (sm != -1)
        {
            index = findIndex(array, size, sm);
            array[i] = sm;
            array[index] = number;
            print_array(array, size);
        }
    }
    
}
