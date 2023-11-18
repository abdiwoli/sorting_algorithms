#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				print_list(*list);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *prev1, *next2;

	prev1 = (*node1)->prev;
	next2 = (*node2)->next;

	if (prev1 != NULL)
		prev1->next = *node2;
	else
		*list = *node2;

	if (next2 != NULL)
		next2->prev = *node1;

	(*node2)->prev = prev1;
	(*node2)->next = *node1;
	(*node1)->prev = *node2;
	(*node1)->next = next2;
}
