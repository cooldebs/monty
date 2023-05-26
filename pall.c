#include "monty.h"

/**
 * pall - prints the stack
 * @stack: stack given by main in main.c
 * @line_count: number of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_count __attribute__((unused)))
{
	print_stack(*stack);
}
