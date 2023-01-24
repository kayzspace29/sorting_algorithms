#include "sort.h"




/**
 * insertion_sort_list - sorts a linked list using the insertion algorithm
 *
 * @list: a pointer to the head of a linked list
 *
 * Return: nothing!
 */
void insertion_sort_list(node **list)
{
	node *temp, *curr, *next;

	if (!(list && *list))
		return;
	curr = (*list)->next;

	while (curr)
	{
		next = curr;
		while (curr->prev && curr->n < curr->prev->n)
		{
			temp = curr->prev;
			temp->next = curr->next;
			if (curr->next)
				curr->next->prev = temp;
			curr->prev = temp->prev;
			curr->next = temp;
			temp->prev = curr;
			if (!curr->prev)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
		}
		curr = next->next;
	}
}
