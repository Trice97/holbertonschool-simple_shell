#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* main - Point d'entrée du programme de test
* Ce programme appelle plusieurs fonctions liées à la gestion
* de l'environnement : affichage des répertoires PATH, construction
* d'une liste chaînée à partir de PATH, ajout et suppression de
* variables d'environnement.
* Return: Always 0.
*/
int main(void)
{
path_node *list, *tmp;

printf("===== Test de print_path_dirs =====\n");
print_path_dirs();

printf("\n===== Test de build_path_list =====\n");
list = build_path_list();
tmp = list;
while (tmp)
{
printf("%s\n", tmp->dir);
tmp = tmp->next;
}
free_path_list(list);

printf("\n===== Test de _setenv =====\n");
_setenv("TEST_VAR", "Hello", 1);
printf("TEST_VAR = %s\n", getenv("TEST_VAR"));

printf("\n===== Test de _unsetenv =====\n");
_unsetenv("TEST_VAR");
printf("TEST_VAR après unset = %s\n", getenv("TEST_VAR"));

return (0);
}
