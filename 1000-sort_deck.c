#include "deck.h"
#include <string.h>

/**
 * cmp_my_cards - name
 * @a:a
 *@b:b
 * Return: int
 */
int cmp_my_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;

	if (card_a->kind != card_b->kind)
		return (card_a->kind - card_b->kind);
	else
		return (strcmp(card_a->value, card_b->value));
}

/**
 * sort_deck - func
 * @deck: cards
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 52, i;
	deck_node_t *deck_array[52];
	deck_node_t *current = *deck;

	for (i = 0; i < deck_size; ++i)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, deck_size, sizeof(deck_node_t *), cmp_my_cards);

	for (i = 0; i < deck_size - 1; ++i)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}

	*deck = deck_array[0];
	(*deck)->prev = NULL;
	deck_array[deck_size - 1]->next = NULL;
}
