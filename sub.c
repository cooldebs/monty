#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_count)
{
	int total;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = total;
}
