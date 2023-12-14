#include "monty.h"
/**
 * push - pushes an element to stack
 * @stack: stack pointer
 * @line_number: argument pointer
 * Return: none
 */
void push(char **stack, unsigned int line_number)
{
	stack_t *element;

	element = malloc(sizeof(stack_t));
	if (element == NULL)
		exit(EXIT_FAILURE)
	element->prev = NULL;
	/*assign n if it exists, else print 0 0 error 0 0*/
	if (line_number)
		element->n = line_number;
	else
		exit(EXIT_FAILURE);
	if (*stack == NULL)
	{
		(*stack) = element;
		element->next = NULL;
	}
	else
	{
		(*stack)->prev = element;
		element->next = *stack;
		*stack = element;
	}
}
