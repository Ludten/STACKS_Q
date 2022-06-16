#include "monty.h"

/**
 * _push - push unto stack
 *
 * @h: head node
 * @args: arguments
 * @line_number: line number
 */
void _push(stack_t **h, char **args, unsigned int line_number)
{
	int n, *p_id;

	if (!IsNumeric(args[1]) || args[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(h);
		p_id = &id;
		*p_id = -1;
		return;
	}

	n = atoi(args[1]);
	if (id == 1)
		add_dnodeint(h, n);
	else if (id == 0)
		add_dnodeint_end(h, n);
}

/**
 * _pall - print all
 *
 * @stack: head node
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	print_dlistint(stack);
}

/**
 * _pint - print integer onto of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: can't pint, stack empty\n", line_number);
		p_id = &id;
		*p_id = -1;
		return;
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - pop top of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int *p_id;

	(void)(line_number);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		p_id = &id;
		*p_id = -1;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
