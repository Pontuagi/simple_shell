#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(__attribute__((unused))int sig_num);
size_t _strcspn(const char *s, const char *look);
void _puts(char *str);
int get_ppid(void);
int get_pid(void);
int _argc(char *buf);
void exit_func(int argc, char **argv);
void execute_cmd(char **argv, char **env);
char *get_path(char *command);
char **tokenize(char *buffer, int argc);
void fork_exec(char **argv, char *path, char **env);
void print_env(char **env);
ssize_t get_line(char **buffer,  FILE *stream);
char *_read_line(void);
char *str_tok(char *str, const char *delim);
void keyword(int argc, char **argv, char **env);
int _setenv(char **argv, char **env);
void _cd(int argc, char **argv);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strchr(const char *s, char c);
int _putchar(char c);
void _exec_file(char *buffer, char **argv, char **env);

#endif
