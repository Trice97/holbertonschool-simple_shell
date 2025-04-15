#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


#define DELIM " \t\r\n"

/* prototype de fonctions */

pid_t getpid(void);
pid_t getppid(void);
char **split_line(char *line);
extern char **environ;


#endif
