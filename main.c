#include "monty.h"

/**
 * main- main file for monty intepreter
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: integer
 */
int main(int argc, char **argv)
{
	File *f;
	char buffer[1024];
	char *cmd;
	size_t buffer_len;
	ssize_t nchars_read;
	unsigned int line_number;
	int count;
	stack_t k_stack;

	buffer_len = 1024;
	line_number = 0;
	count = 0;
	k_stack = NULL;

	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, buffer_len, f))
	{
		count++;
		cmd = strtok(buffer, " ");
		line_number = strtok(NULL, " ");

		switch_cmd(cmd, k_stack, line_number, count);
	}
	fclose(f);
	free_stack(k_stack);
}

/**
 * free_stack- frees stack
 * @k_stack: stack
 * Return: nothing
 */

void free_stack(stack_t k_stack)
{
	stack_t top;

	while (k_stack)
	{
		top = k_stack;
		k_stack = k_stack->next;
		free(top);
	}
}

/**
 * switch_cmd- sitches command
 * @k_stack: stack
 * @line_number: line number
 * @count: keep track of position
 * cmd: entered command
 * Return: nothing
 */

void switch_cmd(char *cmd, char *k_stack, unsigned int line_number, int count)
{
	switch (cmd)
	{
		case "push":
			push(&k_stack, line_number, count);
			break;
		case "pall":
			pall(&k_stack, line_number);
			break;
		case "pint":
			pint(&k_stack, line_number);
			break;
		case "pop":
			pop(&k_stack, line_number);
			break;
		case "swap":
			swap(&k_stack, line_number);
			break;
		case "add":
			add(&k_stack, line_number);
			break;
		case "nop":
			nop(&k_stack, line_number);
			break;
		default:
			fprint(stderr, "L%d: unknown instruction %s\n", count, cmd);
			exit(EXIT_FAILURE);
	}
}
