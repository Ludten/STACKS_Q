#include "monty.h"


/**
 * file_mode - open file
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
