#include "monty.h"

/**
 * is_digit - checks to see if a specific character is a digit
 * @digit: a character to check
 * Return: 1 if it is a digit, 0 otherwise
 */
int is_digit(char digit)
{
	if (digit < '0' || digit > '9')
	{
		return (0);
	}
	return (1);
}

/**
 * is_number - checks to see if a char is a numebr
 * @number: a number to check
 * Return: 1 if the number is a digit, 0 otherwise
 */
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

	value = atoi(arg);

	stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));

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
