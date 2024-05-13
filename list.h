#include <stdbool.h>
#ifndef _LIST_H
#define _LIST_H

typedef struct h_node
{
    struct h_node *prev;
    struct h_node *next;
    char plane_id[5];
    int hist_kind; // 0 - aterrisar 1 - decolar
} Hist_Node;

typedef struct h_list
{
    Hist_Node *head;
    Hist_Node *tail;
    int size;
} Hist_List;
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

Hist_List create_hist_list();
List create_list();
Hist_Node *create_hist_node(char plane_id[5], int kind);
Node *create_node(char plane_id[5]);
bool contains(List *list, char plane_id[5]);
void insert(List *list, char plane_id[5]);
void _remove(List *list, char plane_id[5]);
char *dequeue(List *list);
void append(List *list, char plane_id[5]);
void h_append(Hist_List *list, char plane_id[5], int kind);
char *pop(List *list);

#endif