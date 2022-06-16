#include "monty.h"

/**
 * _stack - set flag to stack format
 *
 * @stack: head node
 * @line_number: line number
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(stack), (void)(line_number);
	p_id = &id;
	*p_id = 1;
}

/**
 * _queue - set flag to queue format
 *
 * @stack: head node
 * @line_number: line number
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(stack), (void)(line_number);
	p_id = &id;
	*p_id = 0;
}

/**
 * _rotl - Rotates the stack to the top.
 *
 * @stack: head node
 * @line_number: line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2, *last;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
		return;
	temp1 = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = (*stack)->next;
	temp2 = *stack;
	temp2->prev = NULL;
	last->next = temp1;
	temp1->prev = last;
	temp1->next = NULL;
}

/**
 * _rotr - Rotates the stack to the bottom.
 *
 * @stack: head node
 * @line_number: line number
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2, *last;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
		return;
	temp1 = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	temp2 = last->prev;
	temp2->next = NULL;
	last->next = temp1;
	temp1->prev = NULL;
}
