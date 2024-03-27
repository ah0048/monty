#include "monty.h"
int data = 0;
/**
 * main - monty interpeter
 * @args: number of arguments
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
		if (commands == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (EXIT_FAILURE);
		}
		if (commands[0] == NULL)
		{
			free2Darray(commands);
			line_number++;
			continue;
		}
		if (strcmp(commands[0], "push") == 0)
		{
			if (commands[1] == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free2Darray(commands);
				fclose(file);
				if (stack)
				freelist(stack);
				return (EXIT_FAILURE);
			}
			else
			{
				data  = atoi(commands[1]);
				if (data == 0 && commands[1][0] != '0')
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_number);
						free2Darray(commands);
						fclose(file);
						if (stack)
						freelist(stack);
						return (EXIT_FAILURE);
					}
			}
		}
			execute(commands[0], &stack, line_number);
			line_number++;
			free2Darray(commands);
	}
		fclose(file);
		freelist(stack);
		return (EXIT_SUCCESS);
}
