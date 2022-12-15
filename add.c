#include "monty.h"

/**
 * opcode_add - adds the top two elements on the stack
 * @stack: a pointer to a stack
 * @line_number: the line number of the instruciton
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + ((*stack)->next)->n;
	((*stack)->next)->n = result;

	opcode_pop(stack, line_number);
}
