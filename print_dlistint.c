#include "monty.h"

void print_dlistint(stack_t **h)
{
	stack_t *temp;

	if (*h == NULL)
		return;

	temp = *h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
