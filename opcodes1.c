#include "monty.h"

/**
 * _swap - swap top of stack and
 * second element of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;
	int *p_id;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp2 = *stack;
	temp->next = temp2->next;
	temp2->next = temp;
	temp->prev = temp2;
	temp2->prev = NULL;
}

/**
 * _nop - do nothing
 *
 * @stack: head node
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack), (void)(line_number);
}

/**
 * _pchar - print ascii value of data
 *
 * @stack: head node
 * @line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int *p_id;
	(void)(line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: can't pchar, stack empty\n", line_number);
		p_id = &id;
		*p_id = -1;
		return;
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * _pstr - print ascii values of data
 * in stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)(line_number);

	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
