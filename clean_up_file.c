#include "monty.h"

/**
 * clean_up_file - close file and exit
 * @file: file to close
*/
void clean_up_file(FILE **file)
{
	if (feof(*file))
	{
		fclose(*file);
		exit(EXIT_SUCCESS);
	}
	if (ferror(*file))
	{
		fclose(*file);
		exit(EXIT_FAILURE);
	}
}
