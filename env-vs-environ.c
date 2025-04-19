#include "main.h"

/**
* main - Affiche l'adresse de 'env' paramètre de main
* et de 'environ' variable globale
* @ac: le nombre d'arguments passées à la ligne de commande
* @av: un tableau de chaine contenant les arguments de la ligne de commande
* @env: un tableau de chaine représentantl'environnement du processus
* Return Always 0
*/

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;


	printf("Adresse de env: %p\n", (void *)env);
	printf("Adresse de environ: %p\n", (void *)environ);

	return (0);
}
