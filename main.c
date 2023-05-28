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
	char buffer[1024], *cmd, *line_number = NULL;
	stack_t *k_stack = NULL;
	int count = 0;

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
		buffer[strcspn(buffer, "\n")] = '\0';
		buffer[strcspn(buffer, "$")] = '\0';
		cmd = strtok(buffer, " ");
		line_number = strtok(NULL, " ");
		if (strcmp(cmd, "#"))
			continue;
		if (strcmp(cmd, "push") == 0)
		{
			if (line_number == NULL || strlen(line_number) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer", count);
				exit(EXIT_FAILURE);
			}
			sw_cmd(cmd, &k_stack, atoi(line_number));
		}
		else
			sw_cmd(cmd, &k_stack, count);
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
 * @cmd: entered command
 * Return: nothing
 */

void sw_cmd(char *cmd, stack_t **k_stack, unsigned int line_number)
{
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
		{"pint", pint},	{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"mul", mul}, {"div2", div2},
		{"mod", mod}, {"pchar", pchar}, {NULL, NULL}};
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
	else if (strcmp(cmd, "sub") == 0)
		instructions[7].f(k_stack, line_number);
	else if (strcmp(cmd, "mul") == 0)
		instructions[8].f(k_stack, line_number);
	else if (strcmp(cmd, "div2") == 0)
		instructions[9].f(k_stack, line_number);
	else if (strcmp(cmd, "mod") == 0)
		instructions[10].f(k_stack, line_number);
	else if (strcmp(cmd, "pchar") == 0)
		instructions[11].f(k_stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
}
