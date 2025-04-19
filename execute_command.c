#include "main.h"

/**
* execute_external - Exécute une commande externe
* @cmd: la commande
*/
void execute_external(char *cmd)
{
pid_t pid = fork();
char *argv[] = {cmd, NULL};

if (pid == 0)
{
	if (execvp(cmd, argv) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}
else if (pid > 0)
{
	wait(NULL);
}
else
{
	perror("fork");
}
}

/**
* execute_command - Interprète une commande
* @cmd: commande utilisateur
*/
void execute_command(char *cmd)
{
char *cmd_copy, *arg;

cmd_copy = strdup(cmd);
if (!cmd_copy)
{
	perror("strdup");
}

arg = strtok(cmd_copy, " ");
if (!arg)
{
	free(cmd_copy);
}

if (strcmp(arg, "setenv") == 0)
	handle_setenv(cmd_copy);
else if (strcmp(arg, "unsetenv") == 0)
	handle_unsetenv(cmd_copy);
else
	execute_external(arg);

free(cmd_copy);
}
