#include "shell.h"

/**
 * main - entry point
 * @ac: the integer argument
 * @av: the string argument
 * Return: Always 0 (Success)
 */

int main(int ac, char **av)
{
itr_r itr[] = {ITR_INIT};
int fd = 2;
if (av == NULL)
return (-1);
if (ac == 2)
{
fd = open(av[1], O_RDONLY);
if (fd < 0)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: No file,can't open it");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
itr->readfd = fd;
}
populate_env_list(itr);
read_history(itr);
hsh(itr, av);
return (EXIT_SUCCESS);
}
