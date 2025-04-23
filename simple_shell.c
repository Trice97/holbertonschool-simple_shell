include "main.h"

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

int simple_shell(int argc, char **argv, char **)
{
	char *line = NULL;

	(void)argc;

	while (1)
	{
		prompt(); /*displayy the prompt*/

		line = read_command();/*read the user's entry*/
	if (!line)
		break;

	if (is_builtin(line))
		execute_builtin(line, env);
	else
		execute_command(line, argv, env);/*external command*/

		free(line);

	}
	return (0);
}
