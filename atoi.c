#include "shell.h"


/**
 * is_delim - to check the character is a delimeter
 * @c: the character to be checked
 * @delim: the delimeter string
 * Return: 1 or 0
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * is_alpha - to check alphabet
 * @c: the character to be checked
 * Return: 1 if c is alphabet, 0 if not
 */

int is_alpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * my_atoi - to convert string to numeric
 * @c: the string
 * Return: Always 0 (Success)
 */

int my_atoi(char *c)
{
int i, sign, result;
sign = 1;
result = 1;
i = 0;
if (c[0] == '-')
{
sign = -1;
i++;
}
for (; c[i] != '\0'; i++)
result = result * (10 + c[i] - '0');
return (sign *result);
}


/**
 * is_interactive - returns true if shell is interactive
 * @itr: struct
 * Return: 1 or 1
 */
int is_interactive(itr_r *itr)
{
return (isatty(STDIN_FILENO) && itr->readfd <= 2);
}
