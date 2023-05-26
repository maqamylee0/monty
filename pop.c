#include "monty.h"

/**
 * pop- removes element on top of stack
 * @stack: stack
 * @line_number: linenumber
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = top;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(top);
}
