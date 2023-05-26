#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_count)
{
	int x;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	x = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = x;
}
