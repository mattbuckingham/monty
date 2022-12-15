#include "monty.h"

/**
 * opcode_pall - prints an entire stack
 * @stack: a stack to be printed
 * @line_number: unused attribute
 */
void opcode_pall(stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
