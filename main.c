#include "monty.h"

/*define global variable argument*/
char *argument;
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
	int line_number = 0;

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
	/* get line from file discriptor */
	while (getline(&line, &n, filed) != -1)
	{
		line_number += 1;
		argument = NULL;
		/*write(STDOUT_FILENO, line, strlen(line));*/
		if (extractopcode(&line, &opcode) == 0)
		{}
		printf("||line number=>%i|line=>%s|len=>%li||\n", line_number, line, strlen(line));
		printf("||opcode-%s|externarg - %s||\n------------------\n", opcode, argument);
			/*executeopcode(opcode, &argument);*/
			/*free(opcode);*/
		if (strlen(line) == 1 || strlen(line) == 0)
			continue;
		printf("beforefree\n");
		free(line);
	}
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
