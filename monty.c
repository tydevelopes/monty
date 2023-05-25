#include "monty.h"

/*char *push_arg = NULL;*/
/*char *opcode = NULL;*/
/*int execution_failed = 0;*/
vars global_vars = {0, NULL, NULL};

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
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	void (*exec_instruction)(stack_t **, unsigned int) = NULL;

	validate_args_count(argc);
	open_monty_file(argv[1], &file);

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		global_vars.opcode = parse_line(buffer);
		if (!global_vars.opcode)
		{
			line_number++;
			continue;
		}
		validate_opcode(global_vars.opcode, line_number);
		if (global_vars.execution_failed)
			clean_up_and_exit(stack, file);

		exec_instruction = get_opcode_func(global_vars.opcode);
		exec_instruction(&stack, line_number);
		if (global_vars.execution_failed)
			clean_up_and_exit(stack, file);
		line_number++;
		free(global_vars.opcode);
		global_vars.opcode = NULL;
		if (global_vars.push_arg != NULL)
			free(global_vars.push_arg);
		global_vars.push_arg = NULL;
	}
	free_stack(stack);
	/*clean_up_file(&file);*/
	fclose(file);

	return (0);
}
