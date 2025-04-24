#include "main.h"

/**
* main - Affiche tous les arguments passées en ligne de commande
* @ac: Nombre d'arguments passés au programme non utiliser
* @av: Tableau de chaine contenant lmes arguments
* Return: always 0
*/

int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}
