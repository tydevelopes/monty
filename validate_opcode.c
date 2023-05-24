#include "monty.h"

/**
 * validate_opcode - check if opcode is valid
 * @opcode: pointer to opcode
 * @line_number: line number of opcode
 */
void validate_opcode(char *opcode, unsigned int line_number)
{
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", "sub", "div", "mul", "mod", NULL};
	int i = 0;
	int is_valid = 0;

	while (opcodes[i] != NULL)
	{
		if (strcmp(opcode, opcodes[i]) == 0)
		{
			is_valid = 1;
			break;
		}
		i++;
	}
	if (!is_valid)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
