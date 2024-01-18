#include "monty.h"

/**
 * push_to_stack - Handles the push opcode, pushes an element to the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	char **command = _strtok(lines[line_number], " \0");

	if (command[1] == NULL || !is_integer(command[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		free_arr(command);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, atoi(command[1]));
	free_arr(command);
}

/**
 * pop_off_stack - Handles the pop opcode, pops an element off the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void pop_off_stack(stack_t **stack, unsigned int line_number)
{
	if (delete_dnodeint_at_index(stack, 0) == -1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
}

/**
 * print_top_stack - Handles the pint opcode, prints the value held by the top
 * element of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void print_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top = get_dnodeint_at_index(*stack, 0);

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}

/**
 * print_all_stack - Handles the pall opcode, prints the values held by each
 * element of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void print_all_stack(stack_t **stack, __attribute__((unused))
		     unsigned int line_number)
{
	print_dlistint(*stack);
}

/**
 * swap_top_stack - Handles the swap opcode, swaps the values held by the two
 * top elements of the stack
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void swap_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top = get_dnodeint_at_index(*stack, 0);
	stack_t *next = get_dnodeint_at_index(*stack, 1);
	int tmp;

	if (top == NULL || next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	tmp = top->n;
	top->n = next->n;
	next->n = tmp;
}
