#include "main.h"

/**
* _which - Recherche un fichier dans les chemins du PATH
* @filename: Le nom du fichier à rechercher
*
* Return: 0 si trouvé, 1 sinon
*/
int _which(char *filename)
{
char *path, *copy, *dir;
struct stat st;
char full_path[1024];

path = getenv("PATH");
if (!path)
	return (1);

copy = strdup(path);
if (!copy)
	return (1);

dir = strtok(copy, ":");

while (dir)
{
	snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
	if (stat(full_path, &st) == 0)
	{
		printf("%s\n", full_path);
		free(copy);
		return (0);
	}
	dir = strtok(NULL, ":");
}

free(copy);
return (1);
}
