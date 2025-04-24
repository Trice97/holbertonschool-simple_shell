#include "main.h"

/**
* print_path_dirs - Affiche chaque répertoire
* contenu dans la variable PATH
* Return: rien
*/
void print_path_dirs(void)
{
char *path;
char *token;
char *path_copy;

path = getenv("PATH");
if (path == NULL)
return;

path_copy = strdup(path);
if (path_copy == NULL)
return;

token = strtok(path_copy, ":");

while (token != NULL)
{
printf("%s\n", token);
token = strtok(NULL, ":");
}

free(path_copy);
}
