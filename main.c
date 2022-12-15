#include "monty.h"

/**
 * main - entry into program
 * @argc: count of args passed
 * @argv: pointer to array of args passed
 * Return: 0 on success, exit other wise
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *command;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &len, file);
	while (read != -1)
	{
		command = strtok(line, " \t\n");
		if (command  == NULL)
		{
			line_number = line_number + 1;
			continue;
		}
		find_opcode(command, &stack, line_number);
		read = getline(&line, &len, file);
		line_number = line_number + 1;
	}
	free(line);
	free_list(stack);
	fclose(file);
	return (0);
}

/**
 * find_opcode - checks the opcode against the command sent through
 * @command: pointer to char represent command
 * @line_number: count of lines executed
 * @stack: pointer to start of stack
 */
void find_opcode(char *command, stack_t **stack, unsigned int line_number)
{
	int i, len;

	instruction_t op[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
/*
 *		{"pint", opcode_pint},
 *		{"pop", opcode_pop},
 *		{"swap", opcode_swap},
 *		{"add", opcode_add},
 *		{"nop", opcode_nop},
*/


		{NULL, NULL}
	};
	len = strlen(command);

	while (command[len - 1] == '$'
	       || command[len - 1] == ' '
	       || command[len - 1] == '\t'
	       || command[len - 1] == '\n')
	{
		command[len - 1] = '\0';
		len = len - 1;
	}

	i = 0;
	while (op[i].opcode != NULL)
	{
		if (strcmp(op[i].opcode, command) == 0)
		{
			op[i].f(stack, line_number);
			return;
		}
		i = i + 1;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);
}

/**
 * free_list - function that frees a stack_t list.
 * @stack: a list to be freed
*/
void free_list(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
