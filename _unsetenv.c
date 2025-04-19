#include "main.h"

/**
* _unsetenv - Supprime une variable d'environnement
* @name: nom de la variable à supprimer
*
* Return: 0 si succès, -1 en cas d'erreur
*/
int _unsetenv(const char *name)
{
int i = 0, j = 0;
size_t len = strlen(name);
char **new_environ;

while (environ[i])
{
	if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
	{
		while (environ[j])
			j++;

		new_environ = malloc(sizeof(char *) * j);
		if (!new_environ)
			return (-1);

		for (i = 0, j = 0; environ[i]; i++)
		{
			if (strncmp(environ[i], name, len) != 0 || environ[i][len] != '=')
			{
				new_environ[j] = environ[i];
				j++;
			}
		}
		new_environ[j] = NULL;
		environ = new_environ;
		return (0);
	}
	i++;
}
return (-1);
}
