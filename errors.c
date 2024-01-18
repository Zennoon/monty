#include "monty.h"

/**
 * malloc_error - Handles any malloc failures and exits
 *
 * Return: void
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
