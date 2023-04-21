#include "shell.h"

/**
 * _strcmp - to compare string pointers.
 * @s1: string 1.
 * @s2: string 2.
 * Return: Always 0 (Success).
 */
int _strcmp(char *s1, char *s2)
{
while ((*s1 && *s2) && (*s1 == *s2))
{
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
 * _strlen - to print the string length
 * @s: the string
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
{
i++;
}
return (i);
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
int i;
for (i = 0; str[i] != '\0'; i++)
{
_putchar(str[i]);
}
_putchar('\n');
}

/**
 * *_strcpy -  string copy
 * @dst: destination
 * @src: string
 * Return: Always 0 (Success)
 */

char *_strcpy(char *dst, char *src)
{
int i = -1;
do {
i++;
dst[i] = src[i];
} while (src[i] != '\0');
return (dst);
}


/**
 * _strcat - concatenating string
 * @dest: destination.
 * @src: source.
 * @a - the first counter
 * @b - the second counter
 * Return: Always 0 (Success)
*/
char *_strcat(char *dest, char *src)
{
int a, b;
a = 0;
b = 0;
while (dest[a] != '\0')
{
a++;
}
while (src[b] != '\0')
{
dest[a] = src[b];
b++;
a++;
}
dest[a] = '\0';
return (dest);
}
