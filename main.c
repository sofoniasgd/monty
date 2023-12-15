#include "monty.h"

/*define global variable argument and stack pointer*/
char *argument = NULL;
stack_t *stacktop = NULL;
instruction_t **functions = NULL;
/* a light weight monty interpreter */
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @envp: enviroment variable
 * Return: always 0
 */
int main(int argc, char *argv[], char *envp[])
{
	FILE *filed;
	size_t n = 0;
	char *fpath, *line = NULL, *opcode = NULL;
	char errmsg[256];
	unsigned int line_number = 0;

	(void)envp;
	/* exit if no or more than one argument then exit if */
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", strlen("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}

	errmsg[0] = '\0';
	fpath = argv[1];

	filed = fopen(fpath, "r");
	if (filed == NULL)
	{
		strcat(errmsg, "Error: Can't open ");
		strcat(errmsg, argv[1]);
		strcat(errmsg, "\n");
		write(STDERR_FILENO, errmsg, strlen(errmsg));
		exit(EXIT_FAILURE);
	}
	/*opcode functions declaration and initialization setup*/
	opcodesetup();
	/* get line from file discriptor */
	while (getline(&line, &n, filed) != -1)
	{
		line_number += 1;
		argument = NULL;
		if (extractopcode(&line, &opcode) == 0)
			continue;
		if (*(line + 0) == '#')
			continue;
		if (executeopcode(opcode, line_number) == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s", line_number, opcode);
			break;
		}

	}
	freefunctions();
	free(line);
	fclose(filed);
	return (0);
}

/**
 * extractopcode - extracts opcode and argument from line
 * @line: line pointer
 * @opcode: opcode pointer
 * Return: status of operation(1 succes, 0 failure)
 */
int extractopcode(char **line, char **opcode)
{
int status = 0, i = 0;
char *delim = " \n", *argumentst, *linen;
/* remove \n from line */
linen = *line;
while (*(linen + i) != '\0')
{
	if (*(linen + i) == '\n')
		*(linen + i) = '\0';
	i++;
}
/* second for finding end of opcode */
*opcode = strtok(linen, delim);
if (*opcode == NULL)
	status = 0;
else
	status = 1;
/* now find next word(argument)*/
argumentst = strtok(NULL, delim);
if (argumentst != NULL)
	argument = argumentst;
return (status);
}

/**
 * opcodesetup - sets up struct definitions for monty opcodes
 * Return: none
 */
void opcodesetup()
{

	int i = 0, opcodelen = 0;
	char *opcodes[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", "sub", "div", "mul", "mod", "pchar", NULL};
	/*find length of the opcode list and malloc an instruction_t pointer array*/
	while (opcodes[opcodelen] != NULL)
		opcodelen += 1;
	functions = malloc(sizeof(instruction_t) * (opcodelen + 1));
	if (functions == NULL)
		mallocerror();
	/* loop to assign function pointers and opcodes */
	for (i = 0; i < opcodelen; i++)
	{
		functions[i] = malloc(sizeof(instruction_t));
		if (functions[i] == NULL)
			mallocerror();
		functions[i]->opcode = opcodes[i];
	}
	functions[i] = NULL;

	functions[0]->f = &push;
	functions[1]->f = &pall;
	functions[2]->f = &pint;
	functions[3]->f = &pop;
	functions[4]->f = &swap;
	functions[5]->f = &add;
	functions[6]->f = &nop;
	functions[7]->f = &sub;
	functions[8]->f = &divide;
	functions[9]->f = &mult;
	functions[10]->f = &mod;
	functions[11]->f = &pchar;
}
/**
 * freefunctions - frees memory reserved for functions
 * Return: none
 */
void freefunctions()
{
	int  i = 0;
	while (functions[i] != NULL)
	{
		free(functions[i]);
		i++;
	}
	free(functions);
}
