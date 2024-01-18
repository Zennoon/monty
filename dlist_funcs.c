#include "monty.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list
 * @head: Pointer to a pointer to the head/first node of the list
 * @n: The value that the new node is going to hold
 *
 * Return: The address of the new node, or NULL if it fails
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		malloc_error();
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}

/**
 * get_dnodeint_at_index - Returns the node at a given index of a doubly linked
 * list
 * @head: Pointer to the head (first node) of the list
 * @index: The index of the required node
 *
 * Return: The node at the index or NULL if it doesn't exist
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int curr_idx = 0;
	stack_t *node_at_idx = NULL;

	while (head)
	{
		if (curr_idx == index)
		{
			node_at_idx = head;
			break;
		}
		curr_idx++;
		head = head->next;
	}
	return (node_at_idx);
}

/**
 * dlistint_len - Returns the number of nodes in a doubly linked list
 * @h: Pointer to the head/first node of the list
 *
 * Return: The number of nodes in the list
 */
size_t dlistint_len(const stack_t *h)
{
	unsigned int num_nodes = 0;

	while (h)
	{
		num_nodes++;
		h = h->next;
	}
	return (num_nodes);
}

/**
 * delete_dnodeint_at_index - Deletes the node at a given index of a doubly
 * linked list if possible
 * @head: Pointer to a pointer to the head/first node of the list
 * @index: Index of the node to delete
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	size_t num_nodes = dlistint_len(*head);
	unsigned int curr_idx = 0;
	stack_t *ptr = *head;

	if (num_nodes == 0 || index >= num_nodes)
		return (-1);
	while (curr_idx < index)
	{
		ptr = ptr->next;
		curr_idx++;
	}
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	if (index == 0)
		*head = ptr->next;
	free(ptr);
	return (1);
}

/**
 * print_dlistint - Prints all the elements of a doubly linked list
 * @h: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const stack_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num_nodes++;
		h = h->next;
	}
	return (num_nodes);
}
