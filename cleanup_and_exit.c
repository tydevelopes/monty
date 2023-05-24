#include "monty.h"

/**
 * clean_up_and_exit - cleanup on failure and exit
 * @stack: pointer to stack
 * @file: pointer to file
 */
void clean_up_and_exit(stack_t *stack, FILE *file)
{
	free(opcode);
	if (push_arg != NULL)
		free(push_arg);
	free_stack(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
