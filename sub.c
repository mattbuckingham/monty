#include "monty.h"

/**
 * opcode_sub - subtracts the top element from the second
 * @stack: a pointer to a stack
 * @line_number: the line number of the instruciton
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n - (*stack)->n;
	((*stack)->next)->n = result;

	opcode_pop(stack, line_number);
}
