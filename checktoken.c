#include "monty.h"
/**
 * checktoken - checks commands after tokenization.
 * @commands: commands double pointers
 * Return: void
 */
int checktoken(char **commands)
{
	if (commands == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (commands[0] == NULL)
	{
		free2Darray(commands);
		return (EXIT_SUCCESS);
	}
    return (2);
}
