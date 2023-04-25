#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

int shell01(char *shpath);
char *prompt(void);
int execprg(char *path, char *shpath);
char **getargs(char *cmd);

extern char **environ;

#endif
