#include "lists.h"
#include <stdlib.h>

/**
* dlistint_len - function that returns number of elements
* @h: doubly linked list
* Return: numbe of elements in a linked list
*/

size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
return (count);
}

/**
* delete_dnodeint_at_index - deletes the node at index
* @head: doubly linked list
* @index: index
* Return: 1 or -1 if it failed
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *delete;
	unsigned int count = 0;
	unsigned int length;

	if ((*head) == NULL)
		return (-1);
	delete = (*head);
	if ((*head)->next == NULL)
	{
		(*head) = NULL;
		return (1);
	}
	length = dlistint_len((*head));
	if (length < index)
		return (-1);
	if (count == index)
	{
		(*head) = (*head)->next;
		if (delete)
		{
			(*head)->prev = NULL;
			free(delete);
			return (1);
		}
	}
	while (count < index)
	{
		if (delete->next == NULL)
			return (-1);
		delete = delete->next;
		count++;
	}
	delete->prev->next = delete->next;
	if (delete->next)
		delete->next->prev = delete->prev;
	free(delete);
return (1);
}
