#include <string.h>
#include "deck.h"


int cmp_my_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;

	if (card_a->kind != card_b->kind)
		return card_a->kind - card_b->kind;
	else
		return strcmp(card_a->value, card_b->value);
}


void my_swap(void *a, void *b, size_t size)
{
	char *temp = malloc(size);
	if (temp == NULL)
		exit(EXIT_FAILURE);

	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);

	free(temp);
}


size_t my_partition(void *array, size_t low, size_t high, size_t size, int (*compare)(const void *, const void *)) {
	char *pivot = (char *)array + high * size;
	size_t i = low - 1;

	for (size_t j = low; j < high; ++j)
	{
		char *current = (char *)array + j * size;
		if (compare(current, pivot) <= 0)
		{
			++i;
			my_swap((char *)array + i * size, current, size);
		}
	}

	my_swap((char *)array + (i + 1) * size, pivot, size);
	return i + 1;
}


void my_quicksort(void *array, size_t low, size_t high, size_t size, int (*compare)(const void *, const void *))
{
    if (low < high)
    {
        size_t partition_index = my_partition(array, low, high, size, compare);

        if (partition_index > 0) {
            my_quicksort(array, low, partition_index - 1, size, compare);
        }
        my_quicksort(array, partition_index + 1, high, size, compare);
    }
}


void my_qsort(void *b, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
	my_quicksort(b, 0, n - 1, size, cmp);
}


void sort_deck(deck_node_t **deck)
{
	size_t dsz = 52, i;
	deck_node_t *deck_array[dsz];
	deck_node_t *current = *deck;

	for (i = 0; i < dsz; ++i)
	{
		deck_array[i] = current;
		current = current->next;
	}

	my_qsort(deck_array, dsz, sizeof(deck_node_t *), cmp_my_cards);

	for (size_t i = 0; i < dsz - 1; ++i)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
    }

	*deck = deck_array[0];
	(*deck)->prev = NULL;
	deck_array[dsz - 1]->next = NULL;
}
