#include <stdbool.h>
#ifndef _LIST_H
#define _LIST_H

typedef struct s_node
{
    struct s_node *prev;
    struct s_node *next;
    char plane_id[5];
} Node;

typedef struct s_list
{
    Node *head;
    Node *tail;
    int size;
} List;

List create_list();
Node *create_node(char plane_id[5]);
bool contains(List *list, char plane_id[5]);
void insert(List *list, char plane_id[5]);
void queue(List *list, char plane_id[5]);
char *dequeue(List *list);
void append(List *list, char plane_id[5]);
char *pop(List *list);

#endif