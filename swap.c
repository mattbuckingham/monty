#include "monty.h"

/**
 * opcode_swap - swaps the top two elements on a stack
 * @stack: a pointer to a stack
 * @line_number: the line number of the instruction
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if ((*stack) == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = tmp;
}

/**
 * opcode_nop - doesn't do anything
 * @stack: attribute unused
 * @line_number: attribute unused
 */
void opcode_nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	;
}
