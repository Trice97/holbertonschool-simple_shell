#include "main.h"

/**
 * read_command - Affiche un prompt et lit la commande de l'utilisateur
 * @buffer: Zone mémoire où stocker la commande
 *
 * Return: Pointeur vers buffer contenant la commande ou NULL si erreur/EOF
 */
char *read_command(char *buffer)
{
	/* Vérifie que le buffer n'est pas NULL */
	if (!buffer)
		return (NULL);

	/* Affiche le prompt */
	printf("#cisfun$ ");
	fflush(stdout);

	/* Lit la commande de l'utilisateur */
	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) /* Gestion d'EOF (CTRL + D) */
	{
		return (NULL);
	}

	/* Supprime le saut de ligne à la fin de la commande */
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
	char *argv[2]; /* Déclare le tableau sans initialisation immédiate */

	/* Vérifie que la commande n'est pas vide */
	if (!commande || *commande == '\0')
		return (-1);

	/* Crée un processus enfant */
	pid = fork();
	if (pid == -1) /* Gestion d'erreur lors de la création du processus */
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0) /* Processus enfant */
	{
		argv[0] = commande; /* Initialise dynamiquement les éléments du tableau */
		argv[1] = NULL;

		/* Exécute la commande avec execve */
		if (execve(commande, argv, environ) == -1)
		{
			perror("./shell"); /* Affiche une erreur si la commande échoue */
			_exit(EXIT_FAILURE);
		}
	}
	else /* Processus parent */
	{
		/* Attend la fin de l'exécution du processus enfant */
		wait(&status);
	}

	/* Retourne 0 en cas de succès */
	return (0);
}
