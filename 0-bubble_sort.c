#include "sort.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * bubble_sort - function sorts array
 * @arr: array of int
 * @size: size;
 */
void bubble_sort(int *arr, size_t size)
{
	size_t i,  flag1 = 0;
	int temp;
	int flag = 1;

	if (arr == NULL || size < 1)
		return;
	while (flag)
	{
		for (i = 0; i < size; i++)
		{
			if (i + 1 < size)
			{
				temp = arr[i + 1];
				if (temp < arr[i])
				{
					arr[i + 1] = arr[i];
					arr[i] = temp;
					print_array(arr, size);
					flag1 = 0;
				}
				else
					flag1++;
			}
			else
				flag1++;
		}
		if (flag1 >= size)
			break;

	}
}
