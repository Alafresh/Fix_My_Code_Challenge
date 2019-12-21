#include "lists.h"
#include <stdlib.h>
/**
*delete_dnodeint_at_index - delete node in that index
*@head: the list
*@index: the index that will be erased
*Return: the list without the index
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int cont = 0;
	dlistint_t *saved;

	if (*head == NULL)
		return (-1);
	saved = *head;
	for (cont = 0; cont < index; cont++)
	{
		if (saved->next)
		{
			saved = saved->next;
		}
		else
		{
			return (-1);
		}
	}
	if (saved == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = saved->next;
		if (saved->next)
		{
			saved->next->prev = NULL;
		}
		free(saved);
		return (1);
	}
	saved->prev->next = saved->next;
	if (saved->next)
	{
		saved->next->prev = saved->prev;
	}
	free(saved);
	return (1);
}
