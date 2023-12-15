#include "monty.h"

/**
 * nop - does nothing
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
/*nothing*/
}
/**
 * add - adds top two elements of stack
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = 0;
	tmp = *stack;
	while (i < 2)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
	tmp = tmp->next;
	tmp->n += (*stack)->n;
	free(*stack);
	*stack = tmp;
}
/**
 * sub - subtracts top element from second top
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = 0;
	tmp = *stack;
	while (i < 2)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
	tmp = tmp->next;
	tmp->n -= (*stack)->n;
	free(*stack);
	*stack = tmp;
}
/**
 * divide - divides top element by second top element
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = 0;
	tmp = *stack;
	while (i < 2)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	
	}
	tmp = *stack;
	tmp = tmp->next;
	tmp->n /= (*stack)->n;
	free(*stack);
	*stack = tmp;
}
/**
 * mult - multoiplies the top two elements
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void mult(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = 0;
	tmp = *stack;
	while (i < 2)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
				exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
	tmp = tmp->next;
	tmp->n *= (*stack)->n;
	free(*stack);
	*stack = tmp;
}
