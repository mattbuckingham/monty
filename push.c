#include "monty.h"

int is_digit(char digit)
{
	if (digit < '0' || digit > '9')
	{
		return (0);
	}
	return (1);
}

int is_number(char *number)
{
	if (*number == '-')
	{
		number = number + 1;
	}
	if (*number == '\0')
	{
		return (0);
	}
	while (*number != '\0')
	{
		if (is_digit(*number) == 0)
		{
			return (0);
		}
		number = number + 1;
	}
	return (1);
}

/**
 * opcode_push - adds new node element to the stack
 * @stack: pointer to pointer to stack_t
 * @line_number: Number of lines of executed
 * Return: Nothing
 */

void opcode_push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *arg;

	if (stack == NULL)
	{
		fprintf(stderr, "Stack not present");
		exit(EXIT_FAILURE);
	}
	arg = strtok(NULL, " \t\n");
	if (arg == NULL || is_number(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*while (arg[i] != '\0')
	  {*/
		/* Make sure no non digit characters in between digits
		   push 0w2 = FAIL
		   push 123 = PASS
		   push -12e = FAIL
		   push -12 = PASS
		   push 222- = FAIL
		   push w12 = FAIL
		   push   -12 = PASS
		*/
		/*if (i > 0 && arg[i - 1] >= '0' && arg[i - 1] <= '9'
			&& (arg[i] < '0' || arg[i] > '9'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (arg[i] != '-' && arg[i] != ' ' && arg[i] != '\t'
		    && (arg[i] < '0' || arg[i] > '9'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i = i + 1;
	}*/

	value = atoi(arg);

	stack_t *new_node = (stack_t*) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
