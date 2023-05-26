#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monty.h"

/**
 * opcode - function for running builtins
 * @stack: stack given by main
 * @string: string to compare
 * @line_count: number of lines
 *
 * Return: void
 */
void opcode(stack_t **stack, char *string, unsigned int line_count)
{
	int x = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(string, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(string, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[x].opcode)
	{
		if (strcmp(op[x].opcode, string) == 0)
		{
			op[x].f(stack, line_count);
			return;
		}
		x++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, string);
	exit(EXIT_FAILURE);
}
