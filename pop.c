#include "monty.h"

/**
 * opcode_pop - removes the top element
 * @stack: a stack to be poped
 * @line_number: unused attribute
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	free(*stack);
	(*stack) = next;
}
