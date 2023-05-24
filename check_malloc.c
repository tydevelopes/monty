#include "monty.h"

/**
 * check_malloc - checks if stack allocation failed
 * @ptr: pointer to allocated memory
 */
void check_malloc_s(stack_t *ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_malloc - checks if char allocation failed
 * @ptr: pointer to allocated memory
 */
void check_malloc_c(char *ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
