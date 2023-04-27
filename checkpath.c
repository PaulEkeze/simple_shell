#include "shell.h"

/**
 * checkpath - checks if the command in the PATH directories
 * @cmd: command string
 *
 * Return: first directory contains the command
 * NULL if the command not in any directory
 */

char *checkpath(char *cmd)
{
	struct stat sb;
	char path[1000];
	char *token;
	char *dir;

	strcpy(path, getenv("PATH"));
	token = strtok(path, ":");
	dir = malloc(100);

	while (token != NULL)
	{
		strcpy(dir, token);
		strcat(dir, "/");
		strcat(dir, cmd);
		if (stat(dir, &sb) == 0)
		{
			return (dir);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
