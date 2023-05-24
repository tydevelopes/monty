#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

extern char *push_arg;
extern char *opcode;

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
} stack_tt;

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
	void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;

void validate_args_count(int argc);
void open_monty_file(char *filename, FILE **file);
void check_malloc(char *ptr);
char *parse_line(char *str);
void validate_opcode(char *opcode, int line_number);
int is_all_digits(char *s);
void push_to_stack(stack_tt **stack, int line_number);
void print_stack(stack_tt **stack, int line_number);
void print_top_of_stack(stack_tt **stack, int line_number);
void delete_top_of_stack(stack_tt **stack, int line_number);
size_t stack_length(const stack_tt *stack);
void swap_top_two(stack_tt **stack, int line_number);
void add_top_two(stack_tt **stack, int line_number);
void do_nothing(stack_tt **stack, int line_number);
void (*get_opcode_func(char *s))(stack_tt **, int);

#endif
