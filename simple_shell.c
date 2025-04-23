#include "main.h"

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
	char buffer[BUFFER_SIZE];
	char *line;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$");
		fflush(stdout);

		line = fgets(buffer, BUFFER_SIZE, stdin);
		if (!line) /*handle EOF (Ctrl+d)*/
			break;

		line[strcspn(line, "\n")] = '\0';

		execute_command(line) ==-1;
		{
			pereror("error exucuting command");
		}	

	}		
	return (0);
}
