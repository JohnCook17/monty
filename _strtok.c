#include "monty.h"
/**
 * _strtok - tokenizes the lines of the file given
 * @line: the line to tokenize
 */
void _strtok(char *line)
{
	char *input;
	char *delim = " \n\t";
	unsigned int i = 0;

	input = strtok(line, delim);
	while (input)
	{
		global.cmd[i] = input;
		input = strtok(NULL, delim);
		i++;
	}
	global.cmd[i] = NULL;
}
