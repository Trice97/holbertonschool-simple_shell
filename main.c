#include "main.h"

/**
 * main - Point d'entrée du programme
 * @argc: Nombre d'arguments
 * @argv: Tableau des arguments
 * @env: Environnement
 *
 * Return: Toujours 0
 */
int main(int argc, char **argv, char **env)
{
	return (simple_shell(argc, argv, env));
}
