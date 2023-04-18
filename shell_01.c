#include "shell.h"

/**
 * shell01 - executes a program without arguments
 *
 * Return: 0 on success
 * 1 on error
 */

int shell01(void)
{
	struct stat sb;
	char path[100];
	extern char **environ;
	char *argv[] = {NULL, NULL};
	pid_t child_p;
	int status;


	while (1)
	{
		printf("#run$ ");
		scanf("%s", path);
	
		if(stat(path, &sb) == -1)
		{
			perror("stat");
			continue;
		}
		child_p = fork();
		if (child_p == 0)
		{
			argv[0] = path;
			execve(path, argv, environ);
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
