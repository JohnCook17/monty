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
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argv[1] == NULL && argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	global.line_number = 1;
	if (argv[1] != NULL)
	{
		FILE *file = fopen(argv[1], "r");

		if (file != NULL)
		{
			while ((nread = getline(&line, &len, file)) != -1)
			{
				_strtok(line);
				op();
				global.line_number += 1;
			}
			fclose(file);
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
	return (0);
}
