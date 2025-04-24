#include "main.h"

/**
* display_prompt - Affiche le prompt "$ " à l'utilisateur
* Return: Rien
*/
void display_prompt(void)
{
printf("$ ");
}

/**
* read_input - Lit une ligne entrée par l'utilisateur
* @line: Pointeur vers la chaîne où stocker la ligne
* @len: Pointeur vers la taille allouée de la ligne
* Return: Le nombre de caractères lus, ou -1 en cas d'erreur
*/
int read_input(char **line, size_t *len)
{
ssize_t nread = getline(line, len, stdin);

if (nread != -1)
(*line)[strcspn(*line, "\n")] = '\0';

return (nread);
}

/**
* tokenize_input - Découpe la ligne en arguments (mots)
* @line: La ligne de commande à découper
* @argv: Tableau pour stocker les arguments
* Return: Rien
*/
void tokenize_input(char *line, char **argv)
{
char *token = strtok(line, " ");
int i = 0;

while (token != NULL)
{
argv[i++] = token;
token = strtok(NULL, " ");
}
argv[i] = NULL;
}

/**
* execute_command - Crée un processus enfant pour exécuter la commande
* @argv: Tableau contenant la commande et ses arguments
* Return: 0 en cas de succès, -1 en cas d'erreur
*/
int execute_command(char **argv)
{
pid_t pid;
int status;

pid = fork();
if (pid == -1)
{
perror("fork");
return (-1);
}
if (pid == 0)
{
if (execve(argv[0], argv, NULL) == -1)
{
perror(argv[0]);
exit(1);
}
}
else
{
wait(&status);
}
return (0);
}

/**
* main - Boucle principale du shell interactif
* Return: Always 0
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char *argv[64];

while (1)
{
display_prompt();
nread = read_input(&line, &len);
if (nread == -1)
{
printf("\n");
break;
}

tokenize_input(line, argv);

if (argv[0] == NULL)
continue;

if (strcmp(argv[0], "exit") == 0)
break;

if (strcmp(argv[0], "cd") == 0)
{
if (argv[1] == NULL || chdir(argv[1]) != 0)
perror("cd");
continue;
}

execute_command(argv);
}

free(line);
return (0);
}
