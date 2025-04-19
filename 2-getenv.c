#include "main.h"
#include <stdio.h>

/**
 * _getenv - Récupère la valeur d'une variable d'environnement
 * @name: le nom de la variable d'environnement à rechercher
 * Return: la valeur de la variable d'environnement si trouvée, sinon NULL
 */
char *_getenv(const char *name)
{
	int i = 0, j, len;

	for (len = 0; name[len] != '\0'; len++)
		;

	while (environ[i] != NULL)
	{
		for (j = 0; j < len && environ[i][j] == name[j]; j++)
			;

		if (j == len && environ[i][j] == '=')
			return (environ[i] + j + 1);

		i++;
	}

	return (NULL);
}

/**
 * main - Teste la fonction _getenv
 *
 * Return: Always 0
 */
int main(void)
{
	char *value;

	value = _getenv("SHELL");
	if (value != NULL)
		printf("SHELL = %s\n", value);
	else
		printf("Variable SHELL non trouvée.\n");

	value = _getenv("USER");
	if (value != NULL)
		printf("USER = %s\n", value);
	else
		printf("Variable USER non trouvée.\n");

	return (0);
}
