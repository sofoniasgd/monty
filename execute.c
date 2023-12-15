#include "monty.h"

/**
 * executeopcode - interprets an opcode
 * @opcode: opcode pointer
 * @line_number: opcode line number
 * Return: 1 if found opcode, 0 otherwise
 */
int executeopcode(char *opcode, unsigned int line_number)
{
	int i = 0, status = 0;

	while (functions[i] != NULL)
	{
		if (strcmp(functions[i]->opcode, opcode) == 0)
		{
			status = 1;
			(*(functions[i]->f))(&stacktop, line_number);
			return (status);
		}
		i++;
	}	


	return (status);
}
/**
 * destroystack - destroys stack
 * Return: none
 */
void destroystack()
{
	stack_t *tmp;

	if (stacktop == NULL)
		return;
	while (stacktop->next != NULL)
	{
		tmp = stacktop->next;
		free(stacktop);
		stacktop = tmp;
	}
	free(stacktop);
}
/**
 * mallocerror - print malloc error
 * Return: none
 */
void mallocerror()
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
