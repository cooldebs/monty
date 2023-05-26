#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @str: string to be checked
 *
 * Return: 1 if SUCCESS
 * 0 for FAILURE
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
	{
		return (0);
	}
	else if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

/**
 * isnumber - checks if a string is a number
 * @string: string to be checked
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(char *string)
{
	int n;

	if (string == NULL)
		return (0);
	for (n = 0; string[n]; n++)
	{
		if (n < '0' || n > '9')
			return (0);
	}
	return (1);
}
