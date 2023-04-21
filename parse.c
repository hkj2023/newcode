#include "shell.h"
#define BUF 1024

/**
 * is_cmd - executable file
 * @itr: user defined typedef
 * @path: path
 * Return: 1 if true, 0 if false
 */
int is_cmd(itr_r *itr, char *path)
{
struct status st;
(void)itr;
if (!path || status(path, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dup_chars - to duplicate string
 * @pathstr: path
 * @start: integer
 * @stop: integer
 * Return: Always 0 (Success)
 */
char *dup_chars(char *pathstr, int start, int stop)
{
char buf[BUF];
int i = 0, k = 0;
for (k = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
buf[k] = 0;
return (buf);
}

/**
 * find_path - to locate path
 * @itr: struct
 * @pathstr: the path
 * @cmd: character
  * Return: Always 0 (Success)
 */
char *find_path(itr_r *itr, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;
if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(itr, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(itr, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}

