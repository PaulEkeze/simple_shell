#include "shell.h"

/**
 * shell - executes a program without arguments
 * @shpath: the shell path
 *
 * Return: 0 on success
 * 1 on error
 */

int shell(char *shpath)
{
	char *cmd;
	size_t len = 0;

	if (isatty(0) == 1)
	{
		while (1)
		{
			cmd = prompt();
			if (cmd == NULL)
			{
				return (1);
			}
			else if (cmd[0] == '\n')
			{
				continue;
			}
			execprg(cmd, shpath);
			free(cmd);
		}
	}
	else
	{
		len = getline(&cmd, &len, stdin);
		if (len == 1)
		{
			return (1);
		}
		execprg(cmd, shpath);
		free(cmd);
	}
	return (0);
}
