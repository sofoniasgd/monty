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
void add(stack_t **stack, __attribute__((unused))unsigned int line_number)
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

