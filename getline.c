#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * get_input - to line of data
 * @itr: user defined data
 * Return: Always 0 (Success)
 */

ssize_t get_input(itr_r *itr)
{
static size_t i = 0, j, len;
ssize_t r;
static char *ch;
char **bufer = &(itr->arg), *p;
_putchar(BUF_FLUSH);
r = _input_buf(itr, &ch, &len);
if (r < 0)
return (-1);
if (len)
{
j = i;
p = ch + i;
check_chain(itr, ch, &j, i, len);
while (j < len)
{
if (is_chain(itr, ch, &j))
break;
j++;
}
i = j + 1;
if (i >= len)
{
i = 0;
len = 0;
i = len;
itr->cmd_buf_type = CMD_NORM;
}
*bufer = p;
return (_strlen(p));
}
*bufer = ch;
return (r);
}

/**
 * _getline - to get input
 * @itr: parameter struct
 * @ptr: pointer
 * @length: length
 * Return: Always 0 (Success)
 */
int _getline(itr_r *itr, char **ptr, size_t *length)
{
char buf[READ_BUF_SIZE];
size_t i = 0, len = 0;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *pp = NULL, *c;
p = *ptr;
if (p && length)
s = *length;
if (i == len)
i = 0;
len = 0;
r = read_buf(itr, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);
c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
pp = _realloc(p, s, s ? s + k : k + 1);
if (!pp)
return (p ? free(p), -1 : -1);
if (s)
_strncat(pp, buf + i, k - i);
else
_strncpy(pp, buf + i, k - i + 1);
s += k - i;
i = k;
p = pp;
if (length)
*length = s;
*ptr = p;
return (s);
}
/**
 * _input_buf - to make buffer
 * @itr: user defined data
 * @buf: the buf string
 * @len: the length of string
 * Return - Always 0 (Success)
 */

ssize_t _input_buf(itr_r *itr, char **buf, size_t *len)
{
ssize_t siz;
size_t length = 0;
siz = 0;
if (!*len)
{

free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
siz = getline(buf, &length, stdin);
#else
siz = _getline(itr, buf, &length);
#endif
if (siz > 0)
{
if ((*buf)[siz - 1] == '\n')
{
(*buf)[siz - 1] = '\0';
siz--;
}
(*itr).line_count = 1;
remove_comments(*buf);
build_history_list(itr, *buf, itr->histcount++);
{
*len = siz;
itr->cmd_buf = buf;
}
}
}
return (siz);
}
/**
 * read_buf - reads a buffer
 * @itr: parameter struct
 * @buf: buffer
 * @i: size
 * Return: Always 0 (Success)
 */
ssize_t read_buf(itr_r *itr, char *buf, size_t *i)
{
ssize_t n = 0;
if (*i)
return (0);
n = read(itr->readfd, buf, READ_BUF_SIZE);
if (n >= 0)
*i = n;
return (n);
}

/**
 * sigintHandler - controller
 * @n: the signal number
 *
*/
void sigintHandler(__attribute__((unused))int n)
{
while (1)
{
_puts("$ ");
_puts("Blinking\n");
sleep(1);
}
return;
}
