#include "monty.h"

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
