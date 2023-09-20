#ifndef LISTME_H
#define LISTME_H
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
extern char **environ;
void childprocess(char *command, char *args[]);
void no_argument(char *command);
void print_env(void);
void handle_me(char *args[]);
void setenvme(int argc, char *args[]);
void handle_semicolon(char *args[], int *argc);
size_t custom_strlen(const char *string);
int custom_strcmp(const char *string1, const char *string2);
char *mycustom_strstr(const char *hay_stack, const char *needle);
int custom_atoi(const char *str);
void tokenize(char *linestring, char *args[], int *argc);
#endif
