#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int shell01(char *shpath);
int execprg(char *path, char *shpath);
char *prompt(void);

extern char **environ;

#endif
