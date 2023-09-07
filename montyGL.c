#include "monty.h"
/**
 * main - Monty interpreter main function
 * @argc: Argument count
 * @argv: Argument values
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char *opcode, *value, *line = NULL;
	size_t line_number = 0, len = 0;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		continue;

		if (strcmp(opcode, "push") == 0)
		{
			value = strtok(NULL, " \t\n");
			if (value == NULL || integer_valid(value))
			{
				fprintf(stderr, "L%lu: usage: push integer\n", line_number);
				fclose(file);
				free(line);
				exit(EXIT_FAILURE);
                        }
			/*printf("%s\n", value);*/
			push(&stack, atoi(value));
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                        pall(&stack, line_number);
                }
		else
		{
			fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(line);
			free_dlistint(stack);
			exit(EXIT_FAILURE);
		}
	free(line); /*libera el bufer de la linea asignada*/
        line = NULL;
        }
        free_dlistint(stack);
	free(line);
	fclose(file);
        return (0);
}
/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
        stack_t *new_node;

        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack != NULL)
                (*stack)->prev = new_node;
        *stack = new_node;
}
/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 */
void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *current = *stack;
        (void)line_number; /*Parametro no utilizado*/

        while (current != NULL)
	{
                printf("%d\n", current->n);
                current = current->next;
        }
}

/**
 * free_dlistint - function that frees a list
 * @head: pointer to the header of the nodes
 * Return: void
 */
void free_dlistint(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
/**
  * integer_valid - Function that checks a valid integer in a string
  * @str: pointer to a string
  * Return: 1 if number is valid or 0 invalid number or empty string
  */
int integer_valid(const char *str)
{
	if (*str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
