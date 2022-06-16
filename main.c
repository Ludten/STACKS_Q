#include "monty.h"

int id = 1;

/**
 * main -entry point
 *
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 (always)
 */
int main(int argc, char **argv)
{
	stack_t *head;
	(void)(argc), (void)(argv);

	head = NULL;
	check_args(argc);
	file_mode(argv[1], &head);
	free_dlistint(&head);
	return (0);
}
