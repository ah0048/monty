#include "main.h"
/**
 * main - monty interpeter
 * @args: number of arguments
 * @argv: the arguments
 * Return: exit status
 */
int main(int argc,char **argv)
{
    char buffer[1024];

    FILE *file;

    char **commands;

    stack_t *stack;

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
        data  = atoi(commands[1]);
        if (data == 0 && commands[1][0] != '0')
        {
            fprintf(stderr, "L%d: usage: push integer", line_number);
            free2Darray(commands);
            return (EXIT_FAILURE);
        }
        execute(commands[0], &stack, line_number);
        line_number++;
        free2Darray(commands);
    }
    fclose(file);
    return (EXIT_SUCCESS);
}
