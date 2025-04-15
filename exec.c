#include "main.h"

/**
 * main - Shell simple qui lit une ligne, découpe et exécute
 * Return: 0 en cas de succès
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;

	printf("$ ");
	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	args = split_line(line);

	if (args[0] == NULL)
	{
		fprintf(stderr, "no command entered\n");
		free(line);
		return (1);
	}

	if (execve(args[0], args, environ) == -1)
	{
		perror("execve");
	}

	free(line);
	return (0);
}
