#include "monty.h"

void free_dlistint(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next;

	if (*head == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
