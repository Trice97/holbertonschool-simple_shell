#include "main.h"

/**
* handle_setenv - Gère la commande setenv
* @cmd: La ligne de commande contenant setenv et ses arguments
*/
void handle_setenv(char *cmd)
{
char *var_name, *var_value;
char *token;

if (cmd == NULL)
	return;

token = strtok(cmd, " ");
token = strtok(NULL, " ");
var_name = token;
token = strtok(NULL, " ");
var_value = token;

if (var_name == NULL || var_value == NULL)
{
	printf("Usage: setenv VARIABLE VALEUR\n");
}

if (_setenv(var_name, var_value, 1) == -1)
	perror("setenv");
}

/**
* handle_unsetenv - Gère la commande unsetenv
* @cmd: La ligne de commande contenant unsetenv et son argument
*/
void handle_unsetenv(char *cmd)
{
char *var_name;
char *token;

if (cmd == NULL)
	return;

token = strtok(cmd, " ");
token = strtok(NULL, " ");
var_name = token;

if (var_name == NULL)
{
	printf("Usage: unsetenv VARIABLE\n");
}

if (_unsetenv(var_name) == -1)
	perror("unsetenv");
}
