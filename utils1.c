#include "monty.h"

/**
 * is_integer - Checks if a string only contains digits or not
 * @str: The string to check
 *
 * Return: 1 if str only contains digits, 0 otherwise
 */
int is_integer(char *str)
{
	while (str && *str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		str++;
	}
	return (1);
}
