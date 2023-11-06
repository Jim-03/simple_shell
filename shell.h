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

/**
 * listint - a singly linked list
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

#endif
