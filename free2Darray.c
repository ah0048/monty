#include "monty.h"
/**
 * free2Darray - free 2D array
 * @str: array of strings
 * Return: void
 */
void free2Darray(char **str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
