#include "shell.h"

/**
 * execprg - executes a program by its path
 * @path: program path string
 * @shpath: the shell path
 *
 * Return: 0 on success
 * -1 on error
 */

int execprg(char *path, char *shpath)
{
	struct stat sb;
	char *argv[] = {NULL, NULL};
	pid_t child_p;
	int status, i = 0;

	while (path[i])
	{
		if (path[i] == '\n')
			path[i] = '\0';
		i++;
	}

	if (stat(path, &sb) == -1)
	{
		perror(shpath);
		return (-1);
	}
	argv[0] = path;

	child_p = fork();
	if (child_p == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_p == 0)
	{
		execve(path, argv, environ);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
