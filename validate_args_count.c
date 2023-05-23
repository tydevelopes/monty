#include "monty.h"

/**
 * validate_args_count - validate argument count
 * @argc: argument count
 */
void validate_args_count(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
