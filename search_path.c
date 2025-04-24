#include "main.h"

/**
 * search_path - Cherche une commande dans le PATH
 * @command: Commande à chercher
 * @env: Environnement
 * Return: Chemin complet si trouvé, NULL sinon
 */
char *search_path(char *command, char **env)
{
	char *path = NULL, *path_copy = NULL, *token = NULL, *full_path = NULL;
	int i = 0, path_len, cmd_len;
	struct stat st;

	if (command == NULL || access(command, X_OK) == 0)
		return (strdup(command));

	while (env[i] != NULL)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
		i++;
	}
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	cmd_len = strlen(command);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		path_len = strlen(token);
		full_path = malloc(path_len + cmd_len + 2);
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
