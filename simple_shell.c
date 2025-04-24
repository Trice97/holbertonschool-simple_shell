#include "main.h"

/**
 * simple_shell - Fonction principale de l'interpréteur
 * @env: Environnement
 * Return: 0
 */
int simple_shell(char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		fflush(stdout);

		nread = read_command(&line, &len, STDIN_FILENO);
		if (nread == -1)
			break;

		for (i = 0; line[i]; i++)
		{
			if (line[i] != ' ' && line[i] != '\t')
				break;
		}
		if (line[i] == '\0')
			continue;

		if (strcmp(line, "exit") == 0)
			break;

		execute_command(line, env); /* Appel corrigé */
		free(line);
		line = NULL;
	}
	free(line);
	return (0);
}
