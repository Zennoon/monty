#include "monty.h"

/**
 * free_dlistint - Frees memory allocated for the nodes of a doubly linked list
 * @head: Pointer to the head (first node) of the list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp = head;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
