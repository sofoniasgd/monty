#include "monty.h"


void printfirst(stack_t __attribute__((unused))**stack, unsigned int __attribute__((unused))line_number)
{
	printf("in push printfirst\n");

}

void push(stack_t __attribute__((unused))**stack, unsigned int __attribute__((unused))line_number)
{
	printf("in push function\n");

}

/**
 * main - test file for function pointer struct
 * Return: always 0
 */
int main(void)
{
stack_t *stack = NULL;
unsigned int line_number = 0;
instruction_t *pushst, *printfirstst;
pushst = malloc(sizeof(instruction_t));
if (pushst == NULL)
{
	printf("malloc error");
	exit(EXIT_FAILURE);
}
printfirstst = malloc(sizeof(instruction_t));
if (printfirstst == NULL)
{
	printf("malloc error");
	exit(EXIT_FAILURE);
}
pushst->opcode = "pushopcode";
pushst->f = &push;
printfirstst->opcode = "printfopcode";
printfirstst->f = &printfirst;

/*use the pointer struct*/
pushst->f(&stack, line_number);
printfirstst->f(&stack, line_number);

return (0);
}
