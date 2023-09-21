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
#include <stdbool.h>
extern char **environ;
void childprocess(char *command, char *args[]);
void print_env(void);
void handle_me_proper(char *args[]);
size_t custom_mystrlen(const char *string);
int custom_strcompare(const char *string1, const char *string2);
int mycustom_atoi(const char *str);
void tokenize_tok(char *linestring, char *args[], int *argc);
#endif
