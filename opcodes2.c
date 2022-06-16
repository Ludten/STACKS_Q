#include "monty.h"

/**
 * _add - add top of stack and second
 * element of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum, *p_id;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}
	temp = *stack;
	sum = temp->n + (temp->next)->n;
	(temp->next)->n = sum;
	_pop(stack, line_number);
}

/**
 * _sub - sub top of stack from second
 * element of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sub, *p_id;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}
	temp = *stack;
	sub = (temp->next)->n - temp->n;
	(temp->next)->n = sub;
	_pop(stack, line_number);
}

/**
 * _div - div second element of stack
 * by top of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int div, *p_id;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}
	temp = *stack;
	div = (temp->next)->n / temp->n;
	(temp->next)->n = div;
	_pop(stack, line_number);
}

/**
 * _mul - mul top of stack and second
 * element of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mul, *p_id;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}
	temp = *stack;
	mul = (temp->next)->n * temp->n;
	(temp->next)->n = mul;
	_pop(stack, line_number);
}

/**
 * _mod - mod second element of stack
 * by top of stack
 *
 * @stack: head node
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mod, *p_id;

	(void)(line_number);

	if (*stack == NULL || dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_dlistint(stack);
		p_id = &id;
		*p_id = -1;
		return;
	}
	temp = *stack;
	mod = (temp->next)->n % temp->n;
	(temp->next)->n = mod;
	_pop(stack, line_number);
}
