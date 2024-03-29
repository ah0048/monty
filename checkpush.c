#include "monty.h"
/**
 * checkpush - checks push argument
 * @commands: double pointer for commands
 * @line_number: line number
 * Return: 0 on success and 1 on failure
 */
int checkpush(char **commands, unsigned int line_number)
{
	int i = 1;

	char *ptr = NULL;

	if (strcmp(commands[0], "push") == 0)
	{
		if (commands[1] == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free2Darray(commands);
			return (EXIT_FAILURE);
		}
		else
		{
			data  = strtol(commands[1], &ptr, 10);
			if (*ptr != '\0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free2Darray(commands);
				return (EXIT_FAILURE);
			}
		}
	}
	while (commands[i])
	{
		if (strcmp(commands[i], "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free2Darray(commands);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
