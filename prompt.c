#include "main.h"

/**
* main - Affiche un prompt "$",lis une ligne avec getline puis l'affiche
* Return: Always 0
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
			printf("$ ");
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			printf("\n");
			break;
		}

		printf("%s", line);
	}

	free(line);

	return (0);
}
