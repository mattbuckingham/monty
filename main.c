#include "monty.h"

/**
 * main - entry into program
 * @argc: count of args passed
 * @argv: pointer to array of args passed
 * Return: 0 on success, exit other wise
  */
int main(int argc, char *argv[])
{
	//check to make sure argv[1] is a path to a file
	//fopen file
	//error if file is not there
	//While loop:
        //    getline from text file
	//    strtok the getline
	//    call corresonding function according to the first word
	//    pass 2nd word as arg
	//    return

	FILE *file;
	char *line = NULL;
	size_t len =0;
	ssize_t read;
	char *command;
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
			line_num = line_num + 1;
			continue;
		}
	}
	free(line);
	fclose(file);
	return (0);
}

/**
 * find_opcode - checks the opcode against the command sent through
 * @command: pointer to char represent command
 * @line_number: count of lines executed
 * @stack: pointer to start of stack
 * Return: 0 on success, 1 on failure
 */
int find_opcode(char *command, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t op[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{NULL, NULL}
	};

	i = 0;
	while (op[i].opcode != NULL)
	{
		if (strcmp(op[i].opcode, command) == 0)
		{
			op[i].f(stack, line_number);
			return (0);
		}
		i = i + 1;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	exit(EXIT_FAILURE);

	return (1);
}
