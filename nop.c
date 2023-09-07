#include "monty.h"
/**
 *nop- nothing
 *@stack: stack struct
 *@line_number: line_number
 *Return: no return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	fprintf(stderr, "L%d: unknown instruction nop\n", line_number);
	exit(EXIT_FAILURE);
}
