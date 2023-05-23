#include "monty.h"

char *push_arg = NULL;

/**
 * main - program starting point
 * @argc: argument's count
 * @argv: argument's values
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	char buffer[BUFFER_SIZE] = {0};
	int line_number = 1;
	char *opcode = NULL;

	validate_args_count(argc);

	open_monty_file(argv[1], &file);

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		opcode = parse_line(buffer);
		if (!opcode)
		{
			line_number++;
			continue;
		}
		validate_opcode(opcode, line_number);
		execute_instruction(opcode, line_number);

		line_number++;
		free(opcode);
		if (push_arg != NULL)
			free(push_arg);
		push_arg = NULL;
	}
	if (feof(file))
		exit(EXIT_SUCCESS);
	if (ferror(file))
		exit(EXIT_FAILURE);
}
