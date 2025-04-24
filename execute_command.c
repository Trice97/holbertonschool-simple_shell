#include "main.h"

/**
 * execute_command - Exécute la commande donnée
 * @command: La commande à exécuter
 * @env: Environnement
 */
void execute_command(char *command, char **env)
{
	pid_t pid;
	int status;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	if (!command || *command == '\0')
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		/* Processus enfant : tenter d'exécuter la commande */
		if (execve(argv[0], argv, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", "./hsh", command);
			_exit(127);
		}
	}
	else
		wait(&status);
}
