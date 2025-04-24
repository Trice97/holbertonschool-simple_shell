#include "main.h"

/**
 * read_command - Lit une ligne depuis l'entrée
 * @lineptr: pointeur vers la ligne lue
 * @n: taille allouée pour la ligne
 * @fd: descripteur de fichier
 * Return: Nombre de caractères lus ou -1 en cas d'erreur
 */
ssize_t read_command(char **lineptr, size_t *n, int fd)
{
	ssize_t nread;

	nread = getline(lineptr, n, fd == STDIN_FILENO ? stdin : fdopen(fd, "r"));
	if (nread == -1)
		return (-1);
	if ((*lineptr)[nread - 1] == '\n')
		(*lineptr)[nread - 1] = '\0';
	return (nread);
}
