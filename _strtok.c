#include "monty.h"

void _strtok(char *line)
{
	char *input;
	char *delim = " ";
	unsigned int i = 0;

	input = strtok(line, delim);
	while (input && i < strlen(line))
	{
		global.cmd[i] = input;
		input = strtok(NULL, delim);
		i++;
	}
}
