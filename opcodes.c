#include "monty.h"

/**
 * opcodesetup - sets up struct definitions for monty opcodes
 *
 * Return: none
 */
void opcodesetup()
{

	int i = 0;
	instruction_t *pushop;

	char *opcodes[];
	instruction_t *functions[];

	opcodes = ["push", "pall", NULL];
	/* loop to assign function pointers and opcodes */
	for (i = 0; opcodes[i] != NULL; i++)
	{
		
	}
}

/**
 * initstruct - initializes a instruction_t struct
 * @opcode: pointer to opcode
 * @fun: functio pointer to corrsponding opcode
 * Return:struct pointer to instruction_t
 */
instruction_t *initstruct(char *opcode, void (*fun)(stack_t **stack, unsigned int line_number))
{

}
