#include "monty.h"

gv global;
/**
 * main - driver file for the monty language interperter
 * @argc: number of args
 * @argv: the args passed
 *Return: 0
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	ssize_t nread;

	global.line_number = 0;
	if (argv[1] == NULL && argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1] != NULL)
	{
		global.file = fopen(argv[1], "r");
		if (global.file != NULL)
		{
			while ((nread = getline(&global.line, &len, global.file)) != -1)
			{
				global.line_number += 1;
				_strtok(global.line);
				if (global.cmd[0])
					op();
			}
			fclose(global.file);
		}
		else
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	_free(&global.head);
/*	_free(global.line); */
	return (0);
}
