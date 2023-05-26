#include "monty.h"

/**
 * pall- print all stack values
 * @line_number: line number
 * @stack: stack
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	(void)line_number;

	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint- print value at top and new line
 * @line_number: line number
 * @stack: stack
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap- swaps top values
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL  || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);

	}
	value = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = value;
}


