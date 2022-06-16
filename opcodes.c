#include "monty.h"

int id = 1;

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

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	print_dlistint(stack);
}

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

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack), (void)(line_number);
	return;
}

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

void _stack(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(stack), (void)(line_number);
	p_id = &id;
	*p_id = 1;
}

void _queue(stack_t **stack, unsigned int line_number)
{
	int *p_id;

	(void)(stack), (void)(line_number);
	p_id = &id;
	*p_id = 0;
}

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

