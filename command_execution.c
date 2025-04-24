#include "main.h"
#include <errno.h>
#include <stdlib.h>

/**
 * execute_command - Exécute la commande donnée (pour Simple shell 0.1).
 * @command: La commande à exécuter (chemin complet).
 */
void execute_command(char *command)
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
		if (execve(argv[0], argv, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", command);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
