#include "monty.h"

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->next = (*head);
	temp->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = temp;

	(*head) = temp;

	return (*head);
}
