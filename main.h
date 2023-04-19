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

void exit_func(char **argv);
void execute_cmd(char **argv, char *buff, char **env);
char *get_path(char *command);
char **tokenize(char *buffer, int argc);
void fork_exec(char **argv, char *path);
void print_env(char **env);

#endif
