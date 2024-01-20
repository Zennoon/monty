#include "monty.h"

/**
 * is_integer - Checks if a string only contains digits or not
 * @str: The string to check
 *
 * Return: 1 if str only contains digits, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (!(str[i] == '-' && i == 0 && (str[i + 1] >= 48 &&
				      str[i + 1] <= 57)))
			return (0);
		}
		str++;
	}
	return (1);
}
