#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_count)
{
	int total;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_count);
	(*stack)->n = total;
}
