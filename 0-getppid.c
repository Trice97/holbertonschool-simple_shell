#include "main.h"

/**
* main - Affiche le PID du processus parent
*Return: always 0
*/

int main(void)
{
	pid_t ppid = getppid();

	printf("PID du parent : %d\n", ppid);

	return (0);
}
