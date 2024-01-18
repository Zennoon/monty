#include "monty.h"

void push_to_stack(stack_t **stack, unsigned int line_number)
{
	char **command = _strtok(lines[line_number], " \0");

	if (command[1] == NULL || !is_integer(command[1]))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		free_arr(command);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, atoi(command[1]));
	free_arr(command);
	return;
}

void pop_off_stack(stack_t **stack, unsigned int line_number)
{
	printf("%s: Pop\n", lines[line_number]);
        return;
}

void print_top_stack(stack_t **stack, unsigned int line_number)
{
	printf("%s: Print top\n", lines[line_number]);
        return;
}

void print_all_stack(stack_t **stack, unsigned int line_number)
{
	print_dlistint(*stack);
}

void swap_top_stack(stack_t **stack, unsigned int line_number)
{
	printf("%s: Swap\n", lines[line_number]);
        return;
}

void add_top_stack(stack_t **stack, unsigned int line_number)
{
	printf("%s: Add\n", lines[line_number]);
        return;
}

void do_nothing(stack_t **stack, unsigned int line_number)
{
	printf("%s: Nothing\n", lines[line_number]);
        return;
}
