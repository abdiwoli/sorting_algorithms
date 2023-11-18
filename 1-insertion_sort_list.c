#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void move_node_to_right(listint_t **head, listint_t *node)
{
	listint_t *nextNode = node->next;
	if (*head == NULL || node == NULL || node->next == NULL)
		return;

	if (node->prev != NULL)
		node->prev->next = nextNode;
	else
		*head = nextNode;

	if (nextNode->next != NULL)
		nextNode->next->prev = node;

	node->next = nextNode->next;
	node->prev = nextNode;
	nextNode->next = node;
	nextNode->prev = node->prev;
}


void swap(listint_t **head)
{
	listint_t *temp = (*head)->next;
	listint_t *temp1 = temp->next;

	if (*head == NULL || (*head)->next == NULL)
		return;
	(*head)->next = temp1;
	(*head)->prev = temp;

	temp->prev = NULL;
	temp->next = *head;

	if (temp1 != NULL)
		temp1->prev = *head;

	*head = temp;
}

int is_smaller(listint_t *head, listint_t *node)
{
	if (head->n > node->n)
		return 1;
	return (0);
}

void insertion_sort_list(listint_t **list)
{
	listint_t  *current, *next, *next2;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do
	{
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
	}
	while (flag);
}
