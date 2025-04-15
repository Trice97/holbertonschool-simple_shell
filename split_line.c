#include "main.h"

/**
 * split_line - Découpe une chaine en tokens (mots)
 * @line: Chaine à découper
 * Return: Tableau de pointeurs vers chaque mot, terminé par NULL
 */
char **split_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int bufsize = 64, i = 0;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n");

	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
