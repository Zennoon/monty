#include "monty.h"

void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructs[] = {
		{"push", push_to_stack},
		{"pop", pop_off_stack},
		{"pint", print_top_stack},
		{"pall", print_all_stack},
		{"swap", swap_top_stack},
		{"add", add_top_stack},
		{"nop", do_nothing}
	};
	void (*func)(stack_t **, unsigned int) = NULL;
	int i;

	for (i = 0; i < 7; i++)
	{
		if (!_strcmp(opcode, instructs[i].opcode))
			func = instructs[i].f;
	}
	return (func);
}


void execute_lines(char **lines, unsigned int line_count, stack_t **stack)
{
	size_t i;
	void (*func)(stack_t **, unsigned int line_number);

	for (i = 0; i < line_count; i++)
	{
		char **command = _strtok(lines[i], " \0");

		func = get_func(command[0]);
		if (func == NULL)
		{
			dprintf(2, "L%lu: unknown instruction %s\n",
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
