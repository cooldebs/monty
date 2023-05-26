#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pstr -  prints the string starting at the top of the stack
 * @stack: stack given by main
 * @line_count: number of lines
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
