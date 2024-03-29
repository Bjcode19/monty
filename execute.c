#include "monty.h"
/**
 * execute - executes the opcode
 * @file: pointerto monty filr
 * @stack: head linked list - stack
 * @counter: line_counter
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"mod", f_mod},
		{"div", f_mod},
		{"mul", f_mul},
		{"queue", f_queue},
		{"stack", f_stack},
		{"rotr", f_stack},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, "\n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{     opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instructin %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
