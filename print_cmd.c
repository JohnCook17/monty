#include "monty.h"

void print_cmd()
{
	int i = 0;

	while(global.cmd[i])
	{
		printf("%s\n", global.cmd[i]);
		i++;
	}
}
