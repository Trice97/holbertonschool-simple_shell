#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define DELIM " \t\r\n"
#define BUFFER_SIZE 1024

/* prototype de fonctions */

pid_t getpid(void);
pid_t getppid(void);
char **split_line(char *line);
extern char **environ;
char *read_command(char *buffer);
void execute_command(char *commande);
int _which(char *filename);


#endif
