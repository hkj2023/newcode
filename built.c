#include "shell.h"

/**
 * _myexit - to exit
 * @itr: user defined struct
 * Return: Always 0 (Success)
 * (0) if info.argv[0] != "exit"
 */
int _myexit(itr_r *itr)
{
int exitcheck;
if (itr->argv[1])
{
exitcheck = _erratoi(itr->argv[1]);
if (exitcheck < 0)
{
itr->status = 2;
print_error(itr, "Wrong number: ");
_eputs(itr->argv[1]);
_eputchar('\n');
return (1);
}
itr->err_num = _erratoi(itr->argv[1]);
return (-2);
}
itr->err_num = -1;
return (-2);
}

/**
 * _mycd - to change working directory
 * @itr: user defined typedef
 * Return: Always 0 (Success)
 */
int _mycd(itr_r *itr)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(itr, "HOME=");
if (!dir)
chdir_ret = chdir((dir = _getenv(itr, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(itr->argv[1], "-") == 0)
{
if (!_getenv(itr, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(itr, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(itr->argv[1]);
if (chdir_ret < 0)
{
print_error(itr, "Error,can't cd to ");
_eputs(itr->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(itr, "PWD="));
_setenv(itr, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _myhelp - to ask help
 * @itr: user defined struct
 * Return: Always 0 (Success)
 */
int _myhelp(itr_r *itr)
{
char **arg_array;
arg_array = itr->argv;
_puts("I think you need help. No function is done \n");
if (0)
_puts(*arg_array);
return (0);
}

