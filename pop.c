#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * pop - removes the top element of the stack.
 * @stack: stack given by main in main.c
 * @line_count: number of lines
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;

	if (*stack == NULL)
	{
		return;
	}
	(*stack)->prev = NULL;
}
