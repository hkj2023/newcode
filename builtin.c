#include "shell.h"

/**
 * _myhistory - to displays history
 * @itr: user defined struct
 *  Return: Always 0 (Success)
 */
int _myhistory(itr_r *itr)
{
print_list(itr->history);
return (0);
}

/**
 * unset_alias - sets alias
 * @itr: user defined struct
 * @str: string
 * Return: Always 0 (Success)
 */
int unset_alias(itr_r *itr, char *str)
{
char *p, c;
int ret;
p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(itr->alias),
get_node_index(itr->alias, node_starts_with(itr->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alias - to set allias
 * @itr: user defined struct
 * @str: string
 * Return: Always 0 (Success)
 */
int set_alias(itr_r *itr, char *str)
{
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(itr, str));
unset_alias(itr, str);
return (add_node_end(&(itr->alias), str, 0) == NULL);
}

/**
 * print_alias - to prints alias
 * @node: node
 * Return: Always 0 (Success)
 */
int print_alias(itr_r *node)
{
char *p = NULL, *a = NULL;
if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - for help
 * @itr: user defined struct
 *  Return: Always 0 (Success)
 */
int _myalias(itr_r *itr)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;
if (itr->argc == 1)
{
node = itr->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; itr->argv[i]; i++)
{
p = _strchr(itr->argv[i], '=');
if (p)
set_alias(itr, itr->argv[i]);
else
print_alias(node_starts_with(itr->alias, itr->argv[i], '='));
}
return (0);
}

