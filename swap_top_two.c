#include "monty.h"

/**
 * swap_top_two - swap top two element of a stack_t
 * @stack: pointer to the list
 * @line_number: line number
 */
void swap_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack || stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack_length(*stack) == 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->next = temp;
		temp->next = NULL;
		temp->prev = *stack;
		/*temp = NULL;*/
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next = (*stack)->next;
		temp->prev = *stack;
		(*stack)->next = temp;
		temp->next->prev = temp;
		/*temp = NULL;*/
	}
}
