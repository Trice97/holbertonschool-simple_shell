#include "shell.h"

/**
* main - Entry point for the simple shell
* @ac: Argument count (unused)
* @av: Argument vector (unused)
*
* Return: 0 on success, or exit status on failure
*/
int main(int ac, char **av)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

(void)ac;
(void)av;

while (1)
{
prompt();
read = getline(&line, &len, stdin);
if (read == -1)
{
free(line);
write(STDOUT_FILENO, "\n", 1);
break;
}
if (line[read - 1] == '\n')
line[read - 1] = '\0';
execute_command(line);
}
free(line);
return (0);
}

