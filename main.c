#include "main.h"

/**
* main - Shell ultra simple
* Return: Always 0
*/
int main(void)
{
char commande[BUFFER_SIZE];

while (1)
{
	if (read_command(commande) == NULL)
		break;

	if (strcmp(commande, "exit") == 0)
		break;

	execute_command(commande);
}
return (0);
}
