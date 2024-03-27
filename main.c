#include "monty.h"
int data = 0;
/**
 * main - monty interpeter
 * @argc: number of arguments
 * @argv: the arguments
 * Return: exit status
 */
int main(int argc, char **argv)
{
	char buffer[1024];

	FILE *file = NULL;

	char **commands = NULL;

	stack_t *stack = NULL;

	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		remove_newline(buffer);
		commands = token(buffer);
		if (checktoken(commands) == EXIT_SUCCESS || commands[0][0] == '#')
		{
			line_number++;
			continue;
		}
		if (checkpush(commands, line_number) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		execute(commands[0], &stack, line_number);
		line_number++;
		free2Darray(commands);
	}
		fclose(file);
		freelist(stack);
		return (EXIT_SUCCESS);
}
