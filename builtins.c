#include "main.h"

/**
 * handle_builtin - Gère les commandes intégrées
 * @args: Tableau d'arguments
 * @env: Environnement
 * Return: 1 si commande traitée, 0 sinon, 2 pour exit
 */
int handle_builtin(char **args, char **env)
{
	int i;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		return (2);  /* Code pour quitter */
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			printf("%s\n", env[i]);
		}
		return (1);
	}

	return (0);  /* Pas une commande intégrée */
}
