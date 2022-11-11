#ifndef MAIN_H
#define MAIN_H

#define RL_BUFSIZE 1024
#define TOKEN_BUFSIZE 64
#define DELIMITERS " \t\r\n\a"

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

char *read_line(void);
char **split_line(char *getline);
int launch(char **arguments);
int shell_execute(char **arguments);

#endif
