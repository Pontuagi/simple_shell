#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int get_ppid(void);
int get_pid(void);
void exit_func(void);
void execute_cmd(char **argv, char **env);
char *get_path(char *command);
char **tokenize(char *buffer, int argc);
void fork_exec(char **argv, char *path);
void print_env(char **env);
ssize_t get_line(char **buffer,  FILE *stream);
char *_read_line(void);

#endif
