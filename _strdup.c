#include "main.h"
/**
 * _strdup - strdup
 * @str: the buffer string to be dupped
 * Return: dup
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;

	char *dup = (char *)malloc(len * sizeof(char));

	if (dup == NULL)
		return (NULL);
	return (strcpy(dup, str));
}
