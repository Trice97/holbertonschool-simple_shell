#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

/**
* read_command - Affiche un prompt et lit la commande de l'utilisateur
* @buffer: Zone mémoire où stocker la commande
*
* Return: Pointeur vers buffer contenant la commande ou NULL si erreur/EOF
*/
char *read_command(char *buffer)
{
size_t len = 0;
ssize_t read;
if (!buffer)
return (NULL);
printf("#cisfun$ ");
fflush(stdout);
read = getline(&buffer, &len, stdin);
if (read == -1)
return (NULL);
buffer[strcspn(buffer, "\n")] = '\0';
return (buffer);
}
/**
* execute_command - Crée un processus enfant pour exécuter une commande
* @commande: Chemin complet de la commande à exécuter
*
* Return: 0 en cas de succès, -1 en cas d'échec
*/
int execute_command(char *commande)
{
pid_t pid;
int status;
char *argv[2];
if (!commande || *commande == '\0')
return (-1);
pid = fork();
if (pid == -1)
{
perror("fork");
return (-1);
}
if (pid == 0)
{
argv[0] = commande;
argv[1] = NULL;
if (execve(commande, argv, environ) == -1)
{
perror("./shell");
_exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
return (0);
}
