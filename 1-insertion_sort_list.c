#include "sort.h"

/**
 * inter_nodes -  Swap two nodes in a listint_t doble linked list.
 * @h: A pointer to the head of the double linked list
 * @n1: A pointer to the first node to swap
 * @n2: The second node to swap
 */
void inter_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sort a doble linked list of integers.
 * @list: a pointer to the head of a double linked list of integer
 * Description: prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			inter_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
