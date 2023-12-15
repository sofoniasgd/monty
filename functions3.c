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
/**
 * pchar - printf char value of top element
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - print string formed from stack elements
 * @stack: stack pointer
 * @line_number: instruction line number
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;
	char string[127];
	int i = 0;
	char c;

	if (*stack == NULL)
		printf("\n");
	current = *stack;
	while (current != NULL)
	{
		if(current->n <= 0 || current->n >= 128)
			break;
		c = current->n;
		string[i] = c;
		i++;
		if (current->next == NULL)
			current = NULL;
		else
			current = current->next;
	}
	printf("%s\n", string);
}
