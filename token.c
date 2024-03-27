#include "main.h"
/**
 * token - tokenizes the buffer
 * @str: the buffer string
 * Return: array of strings for the commands
 */
char **token(char *str)
{
	char *tkn = strtok(str, " ");

	int i = 0;

	char **commands = (char **)malloc(100 * sizeof(char *));

	if (commands == NULL)
	{
		return (NULL);
	}

	while (tkn)
	{
		commands[i] = _strdup(tkn);
		if (commands[i] == NULL)
		{
			free2Darray(commands);
			return (NULL);
		}
		tkn = strtok(NULL, " ");
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
