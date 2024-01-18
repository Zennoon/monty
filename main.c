#include "monty.h"

char **lines = NULL;

/**
 * main - The entry point of the program
 * @ac: Argument Count
 * @av: Argument Vector
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise
 */
int main(int ac, char **av)
{
	char *buffer;
	size_t line_count = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = read_file_content(av[1]);
	lines = parse_lines(buffer, &line_count);
	execute_lines(lines, line_count, &stack);
	free_arr(lines);
	free_dlistint(stack);
	return (EXIT_SUCCESS);
}
