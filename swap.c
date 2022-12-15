#include "monty.h"

void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if((* stack) == NULL || stack == NULL || (* stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	tmp = (* stack)->n;
	(* stack)->n = ((* stack)->next)->n;
	((* stack)->next)->n = tmp;
}

void opcode_nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	;
}
