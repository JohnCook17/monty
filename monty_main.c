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

	if (argv[1] == NULL && argc != 2)
	{
		perror("USAGE: monty file");
		/*_free(&global.stack);*/
		exit(EXIT_FAILURE);
	}
	global.line_number = 1;
	if (argv[1] != NULL)
	{
		global.file = fopen(argv[1], "r");
		if (global.file != NULL)
		{
			while ((nread = getline(&global.line, &len, global.file)) != -1)
			{
				_strtok(global.line);
				op();
				global.line_number += 1;
			}
			fclose(global.file);
		}
		else
		{
			perror("Error: Can't open file ");
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("Error: Can't open file ");
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	_free(&global.stack);
	printf("bye\n");
	return (0);
}
