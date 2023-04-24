#include "shell.h"

/**
 * shell01 - executes a program without arguments
 * @shpath: the shell path
 *
 * Return: 0 on success
 * 1 on error
 */

int shell01(char *shpath)
{
	char *path;
	size_t len = 0;

	/* check if the stdinp on the terminal*/
	if (isatty(0) == 1)
	{
	/* include all interacitve mode functionality */
		while (1)
		{
			path = prompt();
			if (path == NULL)
			{
				return (1);
			}
			else if (path[0] == '\n')
			{
				continue;
			}
			execprg(path, shpath);
		}
	}
	else
	{
	/* include all non interactive functinality */
		len = getline(&path, &len, stdin); /* non-interacitve */
		if (len == 1)
		{
			return (1);
		}
		execprg(path, shpath);
	}
	free(path);

	return (0);
}
