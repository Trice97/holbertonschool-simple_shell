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

extern char **environ;

/**
* struct path_node - structure pour représenter un répertoire du PATH
* @dir: chaîne représentant le répertoire
* @next: pointeur vers le prochain nœud de la liste
*/
typedef struct path_node
{
char *dir;
struct path_node *next;
} path_node;




pid_t getpid(void);
pid_t getppid(void);
char **split_line(char *line);
extern char **environ;
char *read_command(char *buffer);
void execute_command(char *commande);
int _which(char *filename);
char *_getenv(const char *name);
void print_path_dirs(void);
path_node *build_path_list(void);
void free_path_list(path_node *head);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void handle_setenv(char *cmd);
void execute_external(char *cmd);
void handle_unsetenv(char *cmd);



#endif
