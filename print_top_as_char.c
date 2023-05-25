#include "monty.h"

/**
 * print_top_of_stack_as_char - prints top element of a stack_t list
 * @stack: pointer to the list
 * @line_number: line number
 */
void print_top_of_stack_as_char(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		global_vars.execution_failed = 1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		global_vars.execution_failed = 1;
		return;
	}
	printf("%c\n", (*stack)->n);
}
