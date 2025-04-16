#include "main.h"

/**
* read_command - Affiche un prompt et lit la commande
* @buffer: zone mémoire où stocker la commande
* Return: pointeur vers buffer ou NULL en cas d'erreur
*/
char *read_command(char *buffer)
{
printf("#cisfun$ ");
fflush(stdout);

if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
	perror("fgets");
	return (NULL);
}

buffer[strcspn(buffer, "\n")] = 0;
return (buffer);
}

/**
* execute_command - Crée un processus enfant pour exécuter la commande
* @commande: chemin complet de la commande à exécuter
*/
void execute_command(char *commande)
{
pid_t pid;
int status;

pid = fork();
if (pid == -1)
{
	perror("fork");
}
if (pid == 0)
{
	char *argv[] = {commande, NULL};

	execve(commande, argv, NULL);
	perror("execve");
	_exit(1);
}
else
{
	wait(&status);
}
}
