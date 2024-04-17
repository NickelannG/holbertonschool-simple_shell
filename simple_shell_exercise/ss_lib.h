#ifndef _SS_LIB_H
#define _SS_LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef struct list_s
{
	char *n;
	struct list_s *next;
	struct list_s *prev;
} dlistint_t;

char *_getenv(const char *name);
dlistint_t *add_dnodeint_end(dlistint_t **head, char *n);
size_t print_dlistint(const dlistint_t *h);
void free_list(dlistint_t *head);
void free_node(dlistint_t *node);

#endif
