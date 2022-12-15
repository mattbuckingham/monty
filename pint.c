#include "monty.h"

/**
 * opcode_pint - prints the value at the top of the stack,
 * followed by a new line
 * @stack: pointer to top of stack
 * @line_number: line number
 * Return: void
 */

void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
}
