#include "monty.h"

/**
* rotl - rotates the stack to the top.
* @stack: stack head
* @line_count: number of lines
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	stack_t *newnode;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = newnode = *stack;

	while (newnode->next)
		newnode = newnode->next;
	newnode->next = temp;
	temp->prev = newnode;
	*stack = temp->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
