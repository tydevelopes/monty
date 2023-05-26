#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/*extern char *push_arg;*/
/*extern char *opcode;*/
/*extern int execution_failed;*/

/**
 * struct vars - used for global variables
 * @execution_failed: integer
 * @push_arg: pointer to string
 * @opcode: pointer to string
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct vars
{
	int execution_failed;
	char *push_arg;
	char *opcode;
} vars;

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

extern vars global_vars;

void validate_args_count(int argc);
void open_monty_file(char *filename, FILE **file);
void check_malloc_s(stack_t *ptr);
void check_malloc_c(char *ptr);
char *parse_line(char *str);
void validate_opcode(char *opcode, unsigned int line_number);
int is_all_digits(char *s);
void push_to_stack(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top_of_stack(stack_t **stack, unsigned int line_number);
void delete_top_of_stack(stack_t **stack, unsigned int line_number);
size_t stack_length(const stack_t *stack);
void swap_top_two(stack_t **stack, unsigned int line_number);
void add_top_two(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void (*get_opcode_func(char *s))(stack_t **, unsigned int);
void free_stack(stack_t *stack);
void clean_up_file(FILE **file);
void sub_top_two(stack_t **stack, unsigned int line_number);
void div_top_two(stack_t **stack, unsigned int line_number);
void mul_top_two(stack_t **stack, unsigned int line_number);
void mod_top_two(stack_t **stack, unsigned int line_number);
void clean_up_and_exit(stack_t *stack, FILE *file);
void trunc_comment(char *str);
void print_top_of_stack_as_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);

#endif
