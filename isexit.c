#include "shell.h"

/**
 * isexit - checks the command exit
 * @cmd: command string
 *
 * Return: 0 if the command not exit
 * 1 if the command is exit
 */

int isexit(char *cmd)
{
	int i = 0;
	char exit[] = {'e', 'x', 'i', 't', '\0'};
	char *token;
	char temp[10];

	strcpy(temp, cmd);
	token = strtok(temp, " ");

	while (token[i])
	{
		if (token[i] != exit[i])
			return (0);
		i++;
	}

	return (1);
}
