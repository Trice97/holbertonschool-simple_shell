#include <stdio.h>
#include <unistd.h>

/**
 * main - Exemple simple d'utilisation de fork
 *
 * Return: Toujours 0 en cas de succès, 1 en cas d'erreur
 */
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Avant fork\n");

	pid = fork(); /* Création du processus enfant */

	if (pid == -1)
	{
		perror("Erreur :");
		return (1);
	}

	printf("Après fork\n");

	my_pid = getpid(); /* Récupération du PID courant */

	printf("Mon PID est %u\n", my_pid);

	return (0);
}
