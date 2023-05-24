#include "monty.h"

/**
 * get_opcode_func - selects the correct func to execute opcode
 * @s: opcode passed as argument to the program
 * Return: a pointer to the func that corresponds to the opcode given
 */
void (*get_opcode_func(char *s))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
	    {"push", push_to_stack},
	    {"pall", print_stack},
	    {"pint", print_top_of_stack},
	    {"pop", delete_top_of_stack},
	    {"swap", swap_top_two},
	    {"add", add_top_two},
	    {"nop", do_nothing},
	    {"sub", sub_top_two},
	    {"div", div_top_two},
	    {"mul", mul_top_two},
	    {"mod", mod_top_two},
	    {NULL, NULL}};
	int i;

	i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
