#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: stack head
 * @line_count: number of lines
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *top;
	stack_t *down;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	down = *stack;

	while (down->next)
		down = down->next;

	top = down->prev;
	down->next = *stack;
	down->prev = NULL;
	top->next = NULL;
	(*stack)->prev = down;
	*stack = down;
}
