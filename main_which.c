#include "main.h"

/**
* main - Point d'entrée du programme
* @ac: Nombre d'arguments passés au programme
* @av: Tableau de chaînes de caractères représentant les arguments
* Return: 0 en cas de succès, autre valeur en cas d'échec
*/
int main(int ac, char **av)
{
	int i;

	if (ac < 2)

	{
	printf("Usage: %s filename ...\n", av[0]);

	return (1);

	}

	for (i = 1; av[i]; i++)

	_which(av[i]);

	return (0);
}
