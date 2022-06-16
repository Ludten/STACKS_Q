#include "monty.h"

/**
 * add_dnodeint - add data to top
 * of stack
 *
 * @head: Head node
 * @n: data to be pushed to stack
 * Return: Address of new node
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	int *p_id;
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		p_id = &id;
		*p_id = -1;
		return (NULL);
	}

	temp->n = n;
	temp->next = (*head);
	temp->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = temp;

	(*head) = temp;

	return (*head);
}
