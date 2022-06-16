#include "monty.h"

/**
 * rem_ - remove spaces
 *
 * @str: input string
 * Return: Modified string
 */
char *rem_(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

void exec_op(char **args, stack_t **h, int *ltr)
{
	int i;
	instruction_t op[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue}};

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
		}
	}
}

char **tokenise(char *str)
{
	int i;
	char **argv, *token;

	argv = malloc(sizeof(char *) * 10);
	if (argv == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " ");
	i = 0;
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;

	return argv;
}

void check_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

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
			if (input[0] == '\0' || input[0] == '#' || strcmp(input, "\n") == 0)
				continue;
			args = tokenise(input);
			exec_op(args, h, ltr);
			free(args);
		}
	}
	fclose(fptr);
}


int main(int argc, char **argv)
{
	stack_t *head;
	(void)(argc), (void)(argv);

	head = NULL;
	check_args(argc);
	file_mode(argv[1], &head);
	free_dlistint(&head);
	return 0;
}
