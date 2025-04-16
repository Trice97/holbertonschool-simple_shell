#include "main.h"

/**
* main - Crée 5 enfants, chacun exécute "ls -l \tmp"
*Return: Always 0
*/

int main(void)
{
	pid_t child_pid;
	int status;
	int i;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Erreur lors du fork");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("Erreur execve");
				return (1);
			}
		}
		else
		{
			wait(&status);
			printf("Fils %d terminé\n", i + 1);
		}
	}

	return (0);
}
