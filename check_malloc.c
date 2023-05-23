#include "monty.h"

/**
 * check_malloc - checks if allocation failed
 * @ptr: pointer to allocated memory
 */
void check_malloc(char *ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
