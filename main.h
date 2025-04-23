#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define DELIM " \t\r\n"
#define BUFFER_SIZE 1024

extern char **environ;

/* Prototypes des fonctions principales */
int simple_shell(int argc, char **argv, char **env);
char *read_command(char *buffer);
void execute_command(char *command);

#endif /* MAIN_H */
