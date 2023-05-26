#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_count)
{
	int y;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}

	y = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = y;
}
