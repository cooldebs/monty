#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_node - adds a node to the start of the stack
 * @stack: head of the stack
 * @i: number
 *
 * Return: newly created node, else
 * the function will return NULL
 */
stack_t *add_node(stack_t **stack, const int i)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = i;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
	{
		(*stack)->prev = new;
	}
	*stack = new;
	return (new);
}

/**
 * queue_node - adds a node to a stack_t stack in queue_node
 * @stack: head of the stack
 * @i: number of the node
 *
 * Return: newly created node, if memory alocation fails
 * the function returns NULL.
 */
stack_t *queue_node(stack_t **stack, const int i)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (newnode == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->n = i;

	if (!*stack)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*stack = newnode;
		return (newnode);
	}
	while (current)
	{
		if (!current->next)
		{
			newnode->next = NULL;
			newnode->prev = current;
			current->next = newnode;
			break;
		}
		current = current->next;
	}
	return (newnode);
}

/**
 * print_stack - prints the contents of the stack
 * @stack: head of the stack
 *
 * Return: number of elements
 */
size_t print_stack(const stack_t *stack)
{
	size_t x = 0;

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		x++;
	}
	return (x);
}

/**
 * free_stack - frees the list
 * @stack: head of the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
