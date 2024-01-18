#include "monty.h"

/**
 * get_func - Returs the appropriate function to handle an opcode
 * @opcode: The opcode which is handled
 *
 * Return: The function to hanle the opcode, or NULL if opcode is invalid
 */
void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructs[] = {
		{"push", push_to_stack},
		{"pop", pop_off_stack},
		{"pint", print_top_stack},
		{"pall", print_all_stack},
		{"swap", swap_top_stack},
		{"add", add_top_stack},
		{"nop", do_nothing},
		{"sub", sub_top_stack},
		{"div", div_top_stack},
		{"mul", mul_top_stack},
		{"mod", mod_top_stack},
		{"pchar", print_char_top_stack}
	};
	void (*func)(stack_t **, unsigned int) = NULL;
	int i;

	for (i = 0; i < 12; i++)
	{
		if (!_strcmp(opcode, instructs[i].opcode))
			func = instructs[i].f;
	}
	return (func);
}

/**
 * execute_lines - Executes the lines of the monty file
 * @lines: The lines in the file
 * @line_count: The number of lines in the file
 * @stack: The stack used to execute the opcodes in the file
 *
 * Return: void
 */
void execute_lines(char **lines, unsigned int line_count, stack_t **stack)
{
	size_t i;
	void (*func)(stack_t **, unsigned int line_number);

	for (i = 0; i < line_count; i++)
	{
		char **command = _strtok(lines[i], " \0");

		if (command[0] == NULL || command[0][0] == '#')
		{
			free_arr(command);
			continue;
		}
		func = get_func(command[0]);
		if (func == NULL)
		{
			fprintf(stderr, "L%lu: unknown instruction %s\n",
				i + 1, command[0]);
			free_arr(command);
			free_arr(lines);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
		free_arr(command);
		func(stack, i);
	}
}
