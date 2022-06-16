#include "monty.h"

/**
 * exec_op - find and execute opcodes
 *
 * @args: arguments
 * @h: head node
 * @ltr: line number
 */
void exec_op(char **args, stack_t **h, int *ltr)
{
	int i, *p_id;
	instruction_t op[] = {
		{"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"sub", _sub},
		{"mul", _mul}, {"div", _div},
		{"mod", _mod}, {"nop", _nop},
		{"pchar", _pchar},{"pstr", _pstr},
		{"rotl", _rotl}, {"rotr", _rotr},
		{"stack", _stack}, {"queue", _queue}};

	if (strcmp("push", args[0]) == 0)
	{
		_push(h, args, ++*ltr);
	}
	else
	{
		for (i = 0; op[i].opcode; i++)
		{
			if (strcmp(op[i].opcode, args[0]) == 0)
			{
				(op[i].f)(h, ++*ltr);
				break;
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", ++*ltr, args[0]);
				free_dlistint(h);
				p_id = &id;
				*p_id = -1;
				return;
			}
		}
	}
}

/**
 * check_args - check no. of args
 *
 * @argc: argument counter
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * file_mode: open file
 *
 * @filename: file name
 * @h: head node
 */
void file_mode(char *filename, stack_t **h)
{
	FILE *fptr;
	char line[1024], *t_input = NULL, *input = NULL, **args;
	int line_no = 0, *ltr;
	ltr = &line_no;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (fgets(line, sizeof(line), fptr) != NULL)
		{
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			t_input = line;
			input = rem_(t_input);
			if (input[0] == '\0' || input[0] == '#' || input[0] == '\n')
				continue;
			args = tokenise(input);
			exec_op(args, h, ltr);
			free(args);
			if (id == -1)
				break;
		}
	}
	fclose(fptr);
	if (id == -1)
		exit(EXIT_FAILURE);
}
