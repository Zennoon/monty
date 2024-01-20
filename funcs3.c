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
	if ((top->n < 32 || top->n > 127) && !(top->n > 7 && top->n < 12))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number + 1);
		free_dlistint(*stack);
		free_arr(lines);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

/**
 * print_string_stack - Prints the values held in the stack as a collective
 * string
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void print_string_stack(stack_t **stack,
			__attribute__((unused))unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr && ptr->n && ((ptr->n > 31 && ptr->n < 127) ||
				 (ptr->n > 7 && ptr->n < 12)))
	{
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

/**
 * rotate_top_stack - Rotates the stack so the top element becomes the last
 * and the second top becomes the first
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void rotate_top_stack(stack_t **stack,
		      __attribute__((unused)) unsigned int line_number)
{
	stack_t *top = get_dnodeint_at_index(*stack, 0);

	if (top != NULL)
	{
		int top_n = top->n;
		stack_t *ptr = top;

		while (ptr->next)
		{
			ptr->n = ptr->next->n;
			ptr->next->n = top_n;
			ptr = ptr->next;
		}
	}
}

/**
 * rotate_bottom_stack - Rotates the stack so the bottom element of the stack
 * becomes the top and the second bottom element becomes the bottom
 * @stack: Pointer to a pointer to the stack
 * @line_number: The line number that the current opcode is on
 *
 * Return: void
 */
void rotate_bottom_stack(stack_t **stack,
			 __attribute__((unused)) unsigned int line_number)
{
	stack_t *bottom = get_dnodeint_at_index(*stack, 0);

	while (bottom && bottom->next)
		bottom = bottom->next;
	if (bottom != NULL)
	{
		int bottom_n = bottom->n;
		stack_t *ptr = bottom;

		while (ptr->prev)
		{
			ptr->n = ptr->prev->n;
			ptr->prev->n = bottom_n;
			ptr = ptr->prev;
		}
	}
}
