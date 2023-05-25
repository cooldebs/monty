#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "monty.h"

/**
 * push - pushes an element unto the stack
 * @stack: stack head
 * @line_count: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_count)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	else if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
