#include "monty.h"

/**
 *
 *
 *
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
	char *opcode;
	char *value;
	int data, line_num = 0;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file%s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	read = getline(&line, &len, &file);
	while (read != -1)
	{
		opcode = strtok(line, " \t\n");
		value = strtok(NULL, " \t\n");
		data = atoi(value);
		line_num = line_num + 1;
	}
	return (0);
}

void find_opcode(char *opcode, int value)
{
	instruction_t op[] = {
		{'push', opcode_push},
		{'pall', opcode_pall},
		{'pint', opcode_pint},
		{'pop', opcode_pop},
		{'swap', opcode_swap},
		{'add', opcode_add},
		{'nop', opcode_nop},
		{NULL, NULL}
	};
}
