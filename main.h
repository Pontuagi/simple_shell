#ifndef _MAIN_H_
#define _MAIN_H_

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

#define HIST_FILE	".simple_shell_histoy"
#define HIST_MAX	4096

extern char **environ;


/**
 * strstr - singly linked list
 * @nnumber field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


typedef struct passinfo
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
	int readfile;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**and related function
 *@type: n
 
  cnd flag
 *@func: the func
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


int _loopsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
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

int is_command(info_t *, char *);
char *dup_c(char *, int, int);
char *find_p(info_t *, char *, char *);

int loop_loopsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
char *_memoset(char *, char, unsigned int);
void _ffre(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bufree(void **);

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


int _errtoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void rm_comments(char *);

int _mexit(info_t *);
int _owncd(info_t *);
int _ownhelp(info_t *);

char *get_history(info_t *info);
int wrt_hist(info_t *info);
int r_hist(info_t *info);
int build_hist(info_t *info, char *buf, int linecount);
int re_hist(info_t *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_s(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
int is_chain(info_t *, char *, size_t *);
void che_chai(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
int _ownhistory(info_t *);
int _ownalias(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);


void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _ownsetenv(info_t *);
int _myunsetenv(info_t *);
int pof_ev_list(info_t *);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);



#endif
