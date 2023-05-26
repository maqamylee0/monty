#include "monty.h"

/**
 * push- adds an element onto the top of a stack
 * @line_number: linemumber
 * @stack: the stack
 * Return: void(nothing)
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = line_number;
	top->next = NULL;
	top->prev = NULL;

	if (*stack == NULL)
	{
		*stack = top;
	}
	else
	{
		(*stack)->prev = top;
		top->next = *stack;
		*stack = top;
	}
}
