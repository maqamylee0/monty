#include "monty.h"
/**
 * mod- modulus of top elements of stack
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL  || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
