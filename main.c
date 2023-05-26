#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void file_error(char *argv);
void usage_error(void);
int status = 0;

/**
 * main - entry point of the program
 * @argv: list of arguments passed
 * @argc: amount of arguments
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	global.data_struct = 1;
	if (argc != 2)
		usage_error();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_count++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_count);
		line_count++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - prints file error message and exits
 * @argv: argv given by main()
 *
 * Description: print message if it is not possible to open the file
 * Return: void
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * usage_error - prints usage message and exits
 *
 * Description: if user does not give any file or more than
 * one argument to your program
 *
 * Return: void
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
