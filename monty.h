#ifndef MONTY_H
#define MONTY_H

/** header files **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>

/** Global Variables **/
extern char **lines;

/** structs **/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/** Utility function prototypes **/
void *_realloc(void *, unsigned int, unsigned int);
void free_arr(char **);
int _strcmp(char *, char *);
char *_strchr(char *, char);
char **_strtok(char *, char *);
char *read_file_content(char *);
char **parse_lines(char *, size_t *);
void execute_lines(char **, unsigned int, stack_t **);
void malloc_error(void);
int is_integer(char *);

/** Opcode handlers **/
void push_to_stack(stack_t **, unsigned int);
void pop_off_stack(stack_t **, unsigned int);
void print_top_stack(stack_t **, unsigned int);
void print_all_stack(stack_t **, unsigned int);
void swap_top_stack(stack_t **, unsigned int);
void add_top_stack(stack_t **, unsigned int);
void do_nothing(stack_t **, unsigned int);
void sub_top_stack(stack_t **, unsigned int);
void div_top_stack(stack_t **, unsigned int);
void mul_top_stack(stack_t **, unsigned int);
void mod_top_stack(stack_t **, unsigned int);
void print_char_top_stack(stack_t **, unsigned int);

/** Doubly linked list Functions **/
stack_t *add_dnodeint(stack_t **, const int);
stack_t *get_dnodeint_at_index(stack_t *, unsigned int);
size_t dlistint_len(const stack_t *);
int delete_dnodeint_at_index(stack_t **, unsigned int);
size_t print_dlistint(const stack_t *);
void free_dlistint(stack_t *);
#endif
