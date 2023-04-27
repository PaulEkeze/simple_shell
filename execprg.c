#include "shell.h"

/**
 * execprg - executes a program by its path
 * @cmd: command string
 * @shpath: the shell path
 *
 * Return: 0 on success
 * -1 on error
 */

int execprg(char *cmd, char *shpath)
{
	struct stat sb;
	char **argv;
	pid_t child_p;
	int status, i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = '\0';
		i++;
	}
	argv = getargs(cmd);
	if (*argv[0] == '/')
	{
		if (stat(argv[0], &sb) == -1)
		{
			perror(shpath);
			return (-1);
		}
	}
	else
	{
		argv[0] = checkpath(cmd);
		if (argv[0] == NULL)
		{
			perror(shpath);
			return (-1);
		}
	}
	child_p = fork();
	if (child_p == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_p == 0)
		execve(argv[0], argv, environ);
	else
		wait(&status);
	return (0);
}
