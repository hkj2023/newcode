#include "shell.h"

/**
 * starts_with - to checks the haystack
 * @haystack: the string
 * @needle: the needle string
 * Return: Always 0 (Success)
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strdup - to duplicate a string
 * @str: the string to be duplicated
 * Return: Always 0 (Success)
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}
