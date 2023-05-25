#include "monty.h"

/**
 * parse_line - get opcodes from given string
 * @str: pointer to string to parse
 * Return: return pointer to allocated memory storing opcode
 */
char *parse_line(char *str)
{
	char buffer[1024] = {0};
	char delim = ' ';
	int tokens_count = 0;
	int i = 0;

	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		while (*str == delim || isspace(*str))
			str++;
		if (*str == '\0' || *str == '\n')
			break;
		while (*str != delim && !isspace(*str) && *str != '\0' && *str != '\n')
		{
			buffer[i] = *str;
			str++;
			i++;
		}
		buffer[i] = '\0';
		if (tokens_count == 0)
		{
			global_vars.opcode = malloc(sizeof(char) * (strlen(buffer) + 1));
			check_malloc_c(global_vars.opcode);
			strcpy(global_vars.opcode, buffer);
			tokens_count = 1;
		}
		else if (tokens_count == 1)
		{
			global_vars.push_arg = malloc(sizeof(char) * (strlen(buffer) + 1));
			check_malloc_c(global_vars.push_arg);
			strcpy(global_vars.push_arg, buffer);
			break;
		}
		i = 0;
	}
	return (global_vars.opcode);
}
