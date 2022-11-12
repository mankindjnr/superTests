#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int shell_cd(char **args);
int shell_help(char **args __attribute__((unused)));
int shell_exit(char **args __attribute__((unused)));
int shell_launch(char **args __attribute__((unused)));
int shell_execute(char **args);
char *read_line(void);
char **split_line(char *line);
void shell_loop(void);
int num_of_builtins(void);

#endif
