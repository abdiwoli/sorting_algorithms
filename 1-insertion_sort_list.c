#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * insertion_sort_list - function sorts linkedlist
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *current, *next, *next2;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		flag = 0;
		current = *list;

		while (current && current->next)
		{
			next = current->next;
			if (current->n > next->n)
			{
				next2 = next->next;

				current->next = next2;
				if (next2 != NULL)
					next2->prev = current;

				next->prev = current->prev;
				if (current->prev != NULL)
					current->prev->next = next;
				else
					*list = next;

				next->next = current;
				current->prev = next;
				current = *list;
				print_list(*list);
				flag = 1;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}
