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
