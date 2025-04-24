#include "main.h"

/**
 * read_command - Lit une ligne depuis l'entrée.
 * @lineptr: pointeur vers la ligne
 * @n: taille allouée
 * @fd: descripteur (stdin ou pipe)
 * Return: Nombre de caractères lus ou -1 en cas d'erreur.
 */
ssize_t read_command(char **lineptr, size_t *n, int fd)
{
    ssize_t nread;

    nread = getline(lineptr, n, fd == STDIN_FILENO ? stdin : fdopen(fd, "r"));
    if (nread == -1)
        return (-1);

    if ((*lineptr)[nread - 1] == '\n')
        (*lineptr)[nread - 1] = '\0';

    return nread;
}

/**
 * execute_command - Exécute la commande donnée.
 * @command: commande
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[2];

    if (!command || *command == '\0')
        return;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        argv[0] = command;
        argv[1] = NULL;

        if (execve(command, argv, environ) == -1)
        {
            perror("./shell");
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
}
