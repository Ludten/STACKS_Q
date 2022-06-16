#include "monty.h"

/**
 * dlistint_len - length of stack
 *
 * @h: Head node
 * Return: Length of stack
 */
size_t dlistint_len(stack_t *h)
{
	stack_t *temp;
	size_t i;

	if (h == NULL)
		return (0);

	i = 0;
	temp = h;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
