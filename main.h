#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

#define DELIM " \t\r\n"
#define BUFFER_SIZE 1024

extern char **environ;
int simple_shell(char **env);
ssize_t read_command(char **lineptr, size_t *n, int fd);
void execute_command(char *command);
#endif
