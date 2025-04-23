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

/**
 * struct path_node - Structure pour représenter un répertoire du PATH
 * @dir: Chaîne représentant le répertoire
 * @next: Pointeur vers le prochain nœud de la liste
 */
typedef struct path_node
{
	char *dir;
	struct path_node *next;
} path_node;

/* Fonctions principales */
int simple_shell(int argc, char **argv, char **env);
void prompt(void);
char *read_command(char *buffer);

/* Fonctions de gestion des commandes */
int is_builtin(char *command);
int execute_builtin(char *command, char **env);
void execute_command(char *command);

/* Fonctions utilitaires */
char **split_line(char *line);
int _which(char *filename);
char *_getenv(const char *name);
void print_path_dirs(void);
path_node *build_path_list(void);
void free_path_list(path_node *head);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void handle_setenv(char *cmd);
void handle_unsetenv(char *cmd);

#endif /* MAIN_H */
