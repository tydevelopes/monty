#include "monty.h"

/**
 * do_nothing - do nothing
 * @stack: pointer to the list
 * @line_number: line number
 */
void do_nothing(stack_tt **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}
