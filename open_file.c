#include "monty.h"

/**
 * open_monty_file - opens monty file for reading
 * @filename: file path
 * @file: pointer to opened file
 */
void open_monty_file(char *filename, FILE **file)
{
	*file = fopen(filename, "r");
	if (!*file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
