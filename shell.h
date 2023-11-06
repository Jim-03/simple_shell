#ifndef SHELL_H
#define SHELL_H

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

/* convertors from ASCII to integers */
int delim_checker(char c, char *check);
int str_int(char* str);
int is_alpha(char c);
int shell_inter(info_t *info);

/* string functionalities */
char *_strcat(char *dest, char *src);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *start_(char *str, char *beg);
int _strlen(char *str);
#endif
