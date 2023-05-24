#include "monty.h"

/**
 * print_top_of_stack - prints top element of a stack_t list
 * @stack: pointer to the list
 * @line_number: line number
 */
void print_top_of_stack(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
