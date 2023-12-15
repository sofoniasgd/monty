#include "monty.h"
/**
 * push - pushes an element to stack
 * @stack: stack pointer
 * @line_number: argument pointer
 * Return: none
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *element;
	int stat = 0;
	if (argument)
	{
	/* check for zero input */
	if (*(argument) == '0' || (*(argument) == '-' && *(argument + 1) == '0'))
	{
		if (atoi(argument) == 0)
			stat = 1;
	}
	else
		stat = atoi(argument);
	}
	if (!argument || stat == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freefunctions();
		exit(EXIT_FAILURE);
	}
	element = malloc(sizeof(stack_t));
	if (element == NULL)
		mallocerror();
	element->prev = NULL;
	/*assign n if argument exists, else print 0 0 error 0 0*/
	element->n = atoi(argument);
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
/**
 * pall - prints stack
 * @stack: stack pointer
 * @line_number: instruction line number
 * Return: none
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
		return;
	current = *stack;
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
/**
 * pint - prints top element of stack
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
	printf("%i\n", (*stack)->n);
	}
}
/**
 * pop - removes top element of stack
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: cant't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	}

}
/**
 * swap - swaps top two elements of stack
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;
	int i = 0, top;
	tmp = *stack;
	while (i < 2)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
	top = tmp->n;
	tmp = tmp->next;
	(*stack)->n = tmp->n;
	tmp->n = top;
}
