#include "main.h"

/**
 * execute_command - Exécute la commande donnée avec arguments
 * @args: Tableau d'arguments (le premier étant la commande)
 * @env: Environnement
 */
void execute_command(char **args, char **env)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (!args || !args[0])
		return;

	cmd_path = search_path(args[0], env);
	if (!cmd_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd_path, args, env) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			free(cmd_path);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
		free(cmd_path);
	}
}
