#include "main.h"

/**
* main - point d'entrée principal de l'interpréteur
* @argc: nombre d'arguments (non utilisé)
* @argv: tableau d'arguments (non utilisé)
* @env: environnement
* Return: 0
*/
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	return (simple_shell(env));
}
