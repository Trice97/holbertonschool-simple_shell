#include "main.h"

/**
* main - Exécution d'un fork pour observer le parent et l'enfant
* Return: Always 0
*/

int main(void)
{
	pid_t pid, my_pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Erreur lord du fork");
		return (1);
	}

	my_pid = getpid();

	if (pid == 0)
	{
		printf("(enfant) mon PID est %d\n", my_pid);
		printf("(enfant) le PID de mon parent est %d\n", getppid());
	}

	else
	{
		printf("(parent) Mon PID est %d\n", my_pid);
		printf("(parent) j'ai crée un enfant avec le PID %d\n", pid);
	}

	return (0);
}
