#include "monty.h"
/**
 * pstr- prints string from int
 * @line_number: linemumber
 * @stack: the stack
 * Return: void(nothing)
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int num;
	(void)line_number;

	while (top != NULL)
	{
		num = top->n;
		if (num > 127 || num <= 0)
			break;
		printf("%c", num);
		top = top->next;
	}
	printf("\n");
}
/**
 * rotl- rotates upwards
 * @line_number: linemumber
 * @stack: the stack
 * Return: void(nothing)
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int num;
	(void)line_number;

	if (top == NULL || top->next == NULL)
		return;
	num = top->n;
	while (top->next != NULL)
	{
		top->n = top->next->n;
		top = top->next;
	}
	top->n = num;
}
/**
 * rotr-rotates downwards
 * @line_number: linemumber
 * @stack: the stack
 * Return: void(nothing)
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int num;
	(void)line_number;

	if (top == NULL || top->next == NULL)
		return;
	while (top->next != NULL)
	{
		top = top->next;
	}
	num = top->n;
	while (top->prev != NULL)
	{
		top->n = top->prev->n;
		top = top->prev;
	}
	top->n = num;
}
