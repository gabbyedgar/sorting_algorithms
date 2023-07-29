#include "sort.h"

void swap(listint_t *, listint_t *);

/**
 * insertion_sort_list - insertion sort for doubly linked list
 * @list: double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *curr, *prev;

	head = curr = prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = *list;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			curr = head->next;
			swap(head, head->next);
			if (curr->prev == NULL)
				*list = curr;
			print_list((const listint_t *) *list);
			while (curr->prev != NULL)
			{
				if (curr->n >= curr->prev->n)
					break;
				prev = curr->prev;
				swap(prev, curr);
				if (curr->prev == NULL)
					*list = curr;
				print_list((const listint_t *) *list);
			}
		}
		else
			head = head->next;
	}
}

/**
 * swap - function to swap two nodes in a doubly linked list
 * @left: left node to swap
 * @right: right node to swap
 */
void swap(listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	if (right->next != NULL)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}
