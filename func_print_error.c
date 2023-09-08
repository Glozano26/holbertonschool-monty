#include "monty.h"

/**
 * error_usage - Prints a usage error message and exits
 */
void error_usage(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

/**
 * error_file_open - Prints an error file open failure and exits
 * @filename: The name of the file that couldn't be opened
 */
void error_file_open(const char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

/**
 * invalid_instruct - Handles the case of an unknown instruction
 * @line_number: The line number in the script
 * @opcode: The unknown instruction
 * @file: The file pointer to the script file
 * @line: The line buffer (to be freed)
 * @stack: The stack (to be freed)
 */
void invalid_instruct(unsigned long line_number, const char *opcode, FILE *file, char *line, stack_t *stack)
{
	fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
	fclose(file);
	free(line);
	free_dlistint(stack);
	exit(EXIT_FAILURE);
}
