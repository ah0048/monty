#include "main.h"
/**
 * remove_newline - removes newline character
 * @str: string
 * Return: void
 */
void remove_newline(char *str)
{
    char *last_char = strchr(str, '\n');
    if (last_char)
        *last_char = '\0';
}
