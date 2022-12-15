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

/**
 * opcode_div - divides the second element of the stack by the top
 * @stack: a pointer to a stack
 * @line_number: the line number of the instruciton
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: can't div, division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n / (*stack)->n;
	((*stack)->next)->n = result;

	opcode_pop(stack, line_number);
}

/**
 * opcode_mul - multiplies the second element of the stack by the top
 * @stack: a pointer to a stack
 * @line_number: the line number of the instruciton
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n * (*stack)->n;
	((*stack)->next)->n = result;

	opcode_pop(stack, line_number);
}

/**
 * opcode_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: a pointer to a stack
 * @line_number: the line number of the instruciton
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n % (*stack)->n;
	((*stack)->next)->n = result;

	opcode_pop(stack, line_number);
}
