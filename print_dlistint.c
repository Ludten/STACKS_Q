#include "monty.h"

/**
 * print_dlistint - print elements of stack
 *
 * @h: Head node
 */
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
