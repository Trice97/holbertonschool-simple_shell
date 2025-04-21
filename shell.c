#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
* prompt - Affiche le prompt du shell à l'utilisateur.
*
* Description: Cette fonction affiche le symbole "$ " pour inviter
* l'utilisateur à entrer une commande.
*/
void prompt(void)
{
write(STDOUT_FILENO, "$ ", 2);
}

/**
* execute_command - Exécute la commande entrée par l'utilisateur.
* @line: La ligne de commande saisie par l'utilisateur.
*
* Description: Cette fonction crée un processus enfant avec fork().
* Le processus enfant tente d'exécuter la commande entrée avec execve().
* Si la commande échoue, un message d'erreur s'affiche.
* Le processus parent attend la fin de l'exécution du processus enfant.
*/
void execute_command(char *line)
{
pid_t pid;
char *argv[2];

argv[0] = line;
argv[1] = NULL;

pid = fork();
if (pid == -1)
{
perror("fork");
return;
}
if (pid == 0)
{

if (execve(line, argv, NULL) == -1)
{
perror("simple_shell");
exit(EXIT_FAILURE);
}
}
else
{

wait(NULL);
}
}
