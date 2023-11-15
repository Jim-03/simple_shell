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

extern char **environ;

#define INFO_INIT \
{ \
	.field1 = NULL, \
	.field2 = NULL, \
	.field3 = NULL, \
	.value1 = 0, \
	.value2 = 0, \
	.value3 = 0, \
	.value4 = 0, \
	.ptr1 = NULL, \
	.ptr2 = NULL, \
	.ptr3 = NULL, \
	.ptr4 = NULL, \
	.ptr5 = NULL, \
	.size1 = 0, \
	.size2 = 0, \
	.str1 = NULL, \
	.flag1 = 0, \
	.flag2 = 0, \
	.flag3 = 0 \
}

/**
 * struct listint - a singly linked list
 * @num: integer
 * @str: string
 * @next: pointer to next node
 */

typedef struct listint
{
	int num;
	char *str;
	struct listint *next;
} list_t;

/**
 * struct pseudo_arg - stores pseudo-arguments
 * @arg: string argument
 * @argv: array of arg
 * @path: path to current command
 * @argc: number of arguments
 * @error: number of errors
 * @err_num: number of exits
 * @error_flag: number of errors
 * @fname: the file's name
 * @env: local environment
 * @environ: copy of environ from env
 * @history: commands history
 * @alias: command aliases
 * @change: checks for change in environ
 * @status: return status
 * @cmd_buf: pointer to chain commands
 * @chain: types of command chaining
 * @read_file: file descriptor from which to read line input
 * @history: counts history
 */

typedef struct pseudo_arg
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int error;
	int err_num;
	int error_flag;
	char *fname;
	char **environ;
	int change;
	int status;
	char **cmd_buf;
	int chain;
	int read_file;
	int history;
} info_t;

/* convertors from ASCII to integers */

int delim_checker(char c, char *check);
int str_int(char *str);
int is_alpha(char c);
int shell_inter(info_t *info);

/* string functionalities */

char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);
int count_words_2(char *str, char *s);
char *allocate_copy_word(const char *str, int start, int length);
int word_length(const char *str, char d, int *index);
int count_words(const char *str, char d);
char *_strcat(char *dest, char *src);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *start_(char *str, char *beg);
int _strlen(char *str);
char **str_to_wrd(char *str, char *s);
char **str_to_word(char *str, char d);
int str_rep(char **old, char *new_string);
char *dup_chars(char *str, int start, int stop);

/* lists */

list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
int delete_nodeint_at_index(listint_t **head, unsigned int index);
size_t print_listint(const listint_t *h);
void free_list(list_t *head);
size_t listint_len(const listint_t *h);
list_t *starts_with(list_t *head, char *prefix, char c);
ssize_t get_node_index(list_t *h, list_t *n);
char **list_to_strings(list_t *head);

/* memory management */

int free_NULL(void **ptr);
void *_memset(void *p, size_t n, char b);
void string_strings(char *str);
void *re_alloc(void *ptr, size_t old, size_t newer);

/* structure functionalities */

int delim_chain(info_t *info, char *c, size_t *ptr);
void _chain(info_t *info, char *c, size_t *ptr, size_t i, size_t length);
int _replace(info_t *info);
int var_rep(info_t *info);

/* parsing */

int is_exec(char *path);
char *path_finder(char *pathstr, char *cmd);

/* shell */
int _history(info_t *info);
int shell_main(info_t *info, char **av);
int _exiter(info_t *info);
void exit_error(info_t *info);
int dir_changer(info_t *info);

/* alias */

int rem_alias(info_t *info, char *str);
int add_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _alias(info_t *info);

/* environment */

int add_environment(info_t *info, char *var, char *value);
int add_env(info_t *info);
int print_list_env(info_t *info);
int del_env(info_t *info);
int delete_environment(info_t *info, char *var);
int add_env_list(info_t *info);
char *find_env(info_t *info, const char *name);

/* info */

void clear(info_t *info);


#endif
