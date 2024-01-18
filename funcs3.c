#include "monty.h"

/**
 * mod_top_stack - Handles the mod opcode, divs the values held in the two top
 * elements of the stack, pops the top, and stores the remainder in the new top
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void mod_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top = get_dnodeint_at_index(*stack, 0);
	stack_t *next = get_dnodeint_at_index(*stack, 1);

	if (top == NULL || next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	(next->n) %= top->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * print_char_top_stack - Prints the value held at the top of the stack as
 * a character if possible
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void print_char_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top = get_dnodeint_at_index(*stack, 0);

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
