#include "monty.h"

void (*op())()
{
	int i = 0;

	instruction_t fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mult},
		{NULL, NULL}
	};
	while (fun[i].opcode)
	{
		if (strcmp(global.cmd[0], fun[i].opcode) == 0)
		{
			if (strcmp(global.cmd[0], "push") == 0 && global.cmd[1] == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", global.line_number);
				fclose(global.file);
				_free(&global.head);
				exit(EXIT_FAILURE);
			}
			fun[i].f(&global.head, global.line_number);
			break;
		}
		i++;

	}
	if(fun[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", global.line_number, global.line);
		fclose(global.file);
		_free(&global.head);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
