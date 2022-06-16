#include "monty.h"

/**
 * add_dnodeint_end - add data to end
 * of stack
 *
 * @head: Head node
 * @n: data to be added to stack
 * Return: Address of new node
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	int *p_id;
	stack_t *last = *head;
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		p_id = &id;
		*p_id = -1;
		return (NULL);
	}

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = temp;
	temp->prev = last;
	return (temp);
}
