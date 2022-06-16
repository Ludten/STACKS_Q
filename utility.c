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
 * tokenise - create token from
 * argument
 *
 * @str: argument str
 * Return: array of argmuent pointer
 */
char **tokenise(char *str)
{
	int i, *p_id;
	char **argv, *token;

	argv = malloc(sizeof(char *) * 64);
	if (argv == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		p_id = &id;
		*p_id = -1;
		return (NULL);
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

	return (argv);
}

/**
 * IsNumeric - check for int
 *
 * @String: integer string
 * Return: 1 or 0
 */
int IsNumeric(char *String)
{
	size_t i;

	if (String == NULL)
		return (0);
	if (String[0] == '-')
	{
		for (i = 1; i < strlen(String); i++)
		{
			if ((String[i] < '0') || (String[i] > '9'))
				return (0);
		}
	}
	else
	{
		for (i = 0; i < strlen(String); i++)
		{
			if ((String[i] < '0') || (String[i] > '0' + 9))
				return (0);
		}
	}

	return (1);
}
