#include "main.h"

/**
* _setenv - modifie ou ajoute une variable d'environnement
* @name: nom de la variable
* @value: valeur à affecter
* @overwrite: 1 pour écraser si la variable existe déjà, 0 sinon
*
* Return: 0 si succès, -1 en cas d'erreur.
*/
int _setenv(const char *name, const char *value, int overwrite)
{
char *env_string;
size_t len;
int result;

if (name == NULL || value == NULL || strchr(name, '=') != NULL)
return (-1); /* Vérifie la validité des arguments */

if (getenv(name) != NULL && overwrite == 0)
return (0);

len = strlen(name)
+ strlen(value) + 2;
env_string = malloc(len); /* Alloue une nouvelle chaîne "name=value" */
if (env_string == NULL)
return (-1);

sprintf(env_string, "%s=%s", name, value); /* Construit la chaîne finale */

result = putenv(env_string); /* Ajoute à l'environnement (NE PAS FREE) */

return (result);
}
