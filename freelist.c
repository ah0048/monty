#include "monty.h"
/**
* freelist -  free the linked list
* @stack: head pointer
* Return: void
*/
void freelist(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
