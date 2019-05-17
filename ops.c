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
		{NULL, NULL}
	};
	while (fun[i].opcode)
	{
		if (strcmp(global.cmd[0], fun[i].opcode) == 0)
		{
			fun[i].f(&global.head, global.line_number);
		}
		i++;
	}
	return (NULL);
}
