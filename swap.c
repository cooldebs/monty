#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;
	int data = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	data = temp->n;
	temp->n = data;

	temp->n = temp->next->n;
	temp->next->n = data;
}
