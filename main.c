#include "monty.h"

/**
 * main- main file for monty intepreter
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: integer
 */
int main(int argc, char **argv)
{
	FILE *f;
	char buffer[1024];
	char *cmd;
	char *line_number;
	stack_t *k_stack;
	int count;

	k_stack = NULL;
	count = 0;
	line_number = NULL;

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
	while (fgets(buffer, sizeof(buffer), f) != NULL)
	{
		count++;
		buffer[strcspn(buffer, "$")] = '\0';
		cmd = strtok(buffer, " ");
		line_number = strtok(NULL, " ");
		if (strcmp(cmd, "push") == 0)
		{
			if (line_number == NULL || strlen(line_number) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer", count);
				exit(EXIT_FAILURE);
			}
		}
		if (line_number != NULL && strlen(line_number) != 0)
			sw_cmd(cmd, &k_stack, atoi(line_number));
	}
	fclose(f);
	free_stack(&k_stack);
	return (0);
}

/**
 * free_stack- frees stack
 * @k_stack: stack
 * Return: nothing
 */

void free_stack(stack_t **k_stack)
{
	stack_t *top;

	while (*k_stack)
	{
		top = *k_stack;
		*k_stack = (*k_stack)->next;
		free(top);
	}
}

/**
 * sw_cmd- sitches command
 * @k_stack: stack
 * @line_number: line number
 * @count: keep track of position
 * @cmd: entered command
 * Return: nothing
 */

void sw_cmd(char *cmd, stack_t **k_stack, unsigned int line_number)
{
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}};
	if (strcmp(cmd, "push") == 0)
		instructions[0].f(k_stack, line_number);
	else if (strcmp(cmd, "pall") == 0)
		instructions[1].f(k_stack, line_number);
	else if (strcmp(cmd, "pint") == 0)
		instructions[2].f(k_stack, line_number);
	else if (strcmp(cmd, "pop") == 0)
		instructions[3].f(k_stack, line_number);
	else if (strcmp(cmd, "swap") == 0)
		instructions[4].f(k_stack, line_number);
	else if (strcmp(cmd, "add") == 0)
		instructions[5].f(k_stack, line_number);
	else if (strcmp(cmd, "nop") == 0)
		instructions[6].f(k_stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
}
