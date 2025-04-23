#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * simple_shell - Main entry point for the shell program
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 * @env: Environment variables
 *
 * Description: This function represents the main loop of the shell.
 * It continuously reads user input, determines if it is a built-in
 * command or an external command, and executes it accordingly.
 *
 * Return: Always returns 0.
 */
int simple_shell(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)argc;
	(void)argv;
	(void)env;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		fflush(stdout);

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (execute_command(line) == -1)
		{
			perror("error executing command");
		}

		free(line);
		line = NULL;
		len = 0;
	}

	free(line);
	return (0);
}
