#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096
extern char **environ;


/**
 * struct liststr - user defined struct
 * @num: integer
 * @str: a string
 * @next: next node
 */
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;

/**
 *struct sendmessages - to send messages
 *@arg: character string
 *@argv: character string
 *@path: character string
 *@argc: integer
 *@line_count: the error count
 *@err_num: the error
 *@linecount_flag: count flag
 *@fname: filename
 *@env: environment
 *@environ: child
 *@history: history
 *@alias: alias node
 *@env_changed: change environment
 *@status: status
 *@cmd_buf: cmd buffer
 *@cmd_buf_type: type buffer
 *@readfd: to read file from
 *@histcount: count history
 */
typedef struct sendmessages
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} itr_r;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - user defined data
 *@type: the character
 *@func: function pointer
 */
typedef struct builtin
{
char *type;
int (*func)(itr_r *);
} builtin_table;

int hsh(info_t *, char **);
int find_builtin(itr_r *);
void find_cmd(itr_r *);
void fork_cmd(itr_r *);

int is_cmd(itr_r *, char *);
char *dup_chars(char *, int, int);
char *find_path(itr_r *, char *, char *);

int loophsh(char **);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);

int is_interactive(itr_r *);
int is_delim(char, char *);
int _isalpha(int);
int my_atoi(char *);

int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(itr_r *);
int _mycd(itr_r *);
int _myhelp(itr_r *);

int _myhistory(itr_r *);
int _myalias(itr_r *);

ssize_t get_input(itr_r *);
int _getline(itr_r *, char **, size_t *);
void sigintHandler(int);

void clear_info(itr_r *);
void set_info(itr_r *, char **);
void free_info(itr_r *, int);
char *_getenv(itr_r *, const char *);
int _myenv(itr_r *);
int _mysetenv(itr_r *);
int _myunsetenv(itr_r *);
int populate_env_list(itr_r *);

char **get_environ(itr_r *);
int _unsetenv(itr_r *, char *);
int _setenv(itr_r *, char *, char *);

char *get_history_file(itr_r *itr);
int write_history(itr_r *itr);
int read_history(itr_r *itr);
int build_history_list(itr_r *itr, char *buf, int linecount);
int renumber_history(itr_r *itr);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

int is_chain(itr_r *, char *, size_t *);
void check_chain(itr_r *, char *, size_t *, size_t, size_t);
int replace_alias(itr_r *);
int replace_vars(itr_r *);
int replace_string(char **, char *);

#endif
