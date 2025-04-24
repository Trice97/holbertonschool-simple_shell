#include "main.h"

/**
 * main - Affiche l'adresse de 'env' paramètre de main
 *        et de 'environ' variable globale
 * @ac: Le nombre d'arguments passés à la ligne de commande
 * @av: Un tableau de chaînes contenant les arguments de la ligne de commande
 * @env: Un tableau de chaînes représentant l'environnement du processus
 *
 * Return: Always 0 (succès)
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;


	printf("Adresse de env: %p\n", (void *)env);
	printf("Adresse de environ: %p\n", (void *)environ);

	return (0);
}
