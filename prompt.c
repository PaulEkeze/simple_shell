#include "shell.h"

/**
 * prompt - display prompet to get input
 *
 * Return: pointer to the input string
 * -1 on error
 */

char *prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	int linelen;

	if (write(1, "#run$ ", 6) == -1)
	{
		perror("write");
		return (NULL);
	}

	linelen = getline(&line, &len, stdin);

	if (linelen == -1)
	{
		write(1, "\n", 1);
		return (NULL);
	}
	return (line);
}
