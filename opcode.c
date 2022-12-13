#include "monty.h"

/**
 * check_opcode - check and execute the corresponding function
 * @num: integer number
 * 
 * Return: -1 if fails
 */

int check_command(char *opcode, char *command, unsigned int line_number)
{
	int i;

	instruction_t f[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	i = 0;
	while (f[i].opcode != NULL)
	{
		if (strcmp(f[i].opcode, command) == 0)
		{
			check[i].f();
			return (0);
		}
		i = i + 1;
		}
	return (-1);
}
