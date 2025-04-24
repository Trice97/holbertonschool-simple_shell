#include "main.h"

/**
* read_command - Lit une ligne depuis l'entrée.
* @lineptr: pointeur vers la ligne lue
* @n: taille allouée pour la ligne
* @fd: descripteur de fichier (stdin ou pipe)
* Return: Nombre de caractères lus ou -1 en cas d'erreur
*/
ssize_t read_command(char **lineptr, size_t *n, int fd)
{
ssize_t nread;

nread = getline(lineptr, n, fd == STDIN_FILENO ? stdin : fdopen(fd, "r"));

if (nread == -1)
return (-1);

if ((*lineptr)[nread - 1] == '\n')
(*lineptr)[nread - 1] = '\0';

return nread;
}


/**
* execute_command - Exécute la commande donnée.
* @command: La commande à exécuter
*/
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char **argv;
	char *path_command;

	if (!command || *command == '\0')
		return;

	/* Découpe la commande en arguments */
	argv = split_line(command);
	if (!argv || argv[0] == NULL)
	{
		free(argv);
		return;
	}

	/* Recherche dans le PATH si nécessaire */
	path_command = find_command_in_path(argv[0]);
	if (!path_command)
	{
		fprintf(stderr, "%s: Command not found\n", argv[0]);
		free(argv);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(argv);
		free(path_command);
		return;
	}

	if (pid == 0)
	{
		/* Exécute la commande */
		if (execve(path_command, argv, environ) == -1)
		{
			perror("./shell");
			free(argv);
			free(path_command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(argv);
	free(path_command);
}
