#include "monty.h"
/**
 * mod - remainder of dividision of top element by second top element
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i = 0;
	tmp = *stack;
	while (i < 2)
	{
		if (tmp == NULL)
		{
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
	tmp->n = tmp->n % (*stack)->n;
	free(*stack);
	*stack = tmp;
}
