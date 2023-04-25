#include "shell.h"

/**
 * getargs - split and create array of arguments for
 * the executable program
 * @cmd: string contains the program path and args
 *
 * Return: array of arguments on Success
 */

char **getargs(char *cmd)
{
	char *argv[100];
	char **argvp = argv;
	int i = 0;

	argv[0] = strtok(cmd, " ");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}


	return (argvp);
}
