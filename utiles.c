#include "main.h"

/**
 * read_command - Affiche un prompt et lit la commande de l'utilisateur
 * @buffer: Zone mémoire où stocker la commande
 * Return:Pointeur vers buffer contenant commande ou NULL si cas d'erreur/EOF
 */
char *read_command(char *buffer)
{
	printf("#cisfun$ ");
	fflush(stdout);

	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) /*Gestion d'EOF (CTRL + D)*/
	{
		return (NULL);
	}

	buffer[strcspn(buffer, "\n")] = '\0'; /*supprime le saut de ligne*/
	return (buffer);
}

/**
 * execute_command - Crée un processus enfant pour exécuter une commande
 * @commande: Chemin complet de la commande à exécuter
 */
void execute_command(char *commande)
{
	pid_t pid;
	int status;

	if (!commande || *commande == '\0') /*gestion des commandes vides*/
		return;

	pid = fork();
	if (pid == -1) /*erreur de creation de processus*/
	{
		perror("fork");
		return;
	}

	if (pid == 0) /*processus enfant*/
	{
		char *argv[] = {commande, NULL};

		if (execve(commande, argv, environ) == -1) /*excecution de la commande*/
		{
			perror("./shell"); /*affiche une erreursi la commande echoue*/
			_exit(EXIT_FAILURE);
		}
	}
	else/*process parent*/
	{
		wait(&status);/*attend la fin de 'execution de l'enfant*/
	}
}
