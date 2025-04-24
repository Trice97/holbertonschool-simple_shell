#include "main.h"

/**
 * simple_shell - Fonction principale de l'interpréteur
 * @env: Environnement
 * Return: 0
 */
int simple_shell(char **env)
{
	char *line = NULL, *args[BUFFER_SIZE], *token;
	size_t len = 0;
	ssize_t nread;
	int i, builtin_status, empty_line;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		fflush(stdout);

		nread = read_command(&line, &len, STDIN_FILENO);
		if (nread == -1)
			break;

		/* Vérifier si la ligne est vide */
		empty_line = 1;
		for (i = 0; line[i]; i++)
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				empty_line = 0;
		if (empty_line)
			continue;

		/* Parser la ligne en arguments */
		i = 0;
		token = strtok(line, DELIM);
		while (token != NULL && i < BUFFER_SIZE - 1)
		{
			args[i++] = token;
			token = strtok(NULL, DELIM);
		}
		args[i] = NULL;

		/* Vérifier si c'est une commande intégrée */
		builtin_status = handle_builtin(args, env);
		if (builtin_status == 2)  /* Commande exit */
			break;
		else if (builtin_status == 0)  /* Pas une commande intégrée */
			execute_command(args, env);

		free(line);
		line = NULL;
	}
	free(line);
	return (0);
}
