#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_count)
{
	int total;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
		;
		return;
	}

	total = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = total;
}
