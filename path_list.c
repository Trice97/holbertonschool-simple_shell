#include "main.h"

/**
* add_node_to_path_list - Ajoute un nouveau nœud à la fin de la liste PATH.
* @head: Pointeur vers la tête de la liste.
* @tail: Pointeur vers le dernier nœud de la liste.
* @dir: Le répertoire à ajouter au nœud.
* Return: Pointeur vers le nouveau nœud, ou NULL en cas d'erreur.
*/
path_node *add_node_to_path_list(path_node **head, path_node **tail, char *dir)
{
path_node *new_node = malloc(sizeof(path_node));
if (new_node == NULL)
return (NULL);

new_node->dir = strdup(dir);
new_node->next = NULL;

if (*head == NULL)
*head = *tail = new_node;
else
{
(*tail)->next = new_node;
*tail = new_node;
}
return (new_node);
}

/**
* build_path_list - construit une liste chaînée des répertoires du PATH
* Return: Pointeur vers la tête de la liste, ou NULL en cas d'erreur.
*/
path_node *build_path_list(void)
{
char *path;
char *token;
char *path_copy;
path_node *head;
path_node *tail;
path_node *new_node;

path = getenv("PATH");
head = NULL;
tail = NULL;

if (path == NULL)
return (NULL);
path_copy = strdup(path);
if (path_copy == NULL)
return (NULL);

token = strtok(path_copy, ":");

while (token != NULL)
{
new_node = add_node_to_path_list(&head, &tail, token);



if (new_node == NULL)
{
free(path_copy);
free_path_list(head);
return (NULL);
}
token = strtok(NULL, ":");
}

free(path_copy);
return (head);
}

/**
* free_path_list - libère la mémoire allouée pour la liste chaînée
* @head: tête de la liste
* Return: rien.
*/
void free_path_list(path_node *head)
{
path_node *tmp;

while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp->dir);
free(tmp);
}
}
