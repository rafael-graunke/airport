#include <stdlib.h>
#include <string.h>
#include "list.h"

#include <stdio.h>

List create_list()
{
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

Hist_List create_hist_list()
{
    Hist_List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

bool contains(List *list, char plane_id[5])
{

    Node *curr = list->head;
    if (curr == NULL)
    {
        return false;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (strcmp(curr->plane_id, plane_id) == 0)
        {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

Node *create_node(char plane_id[5])
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    strcpy(node->plane_id, plane_id);

    return node;
}

Hist_Node *create_hist_node(char plane_id[5], int kind)
{
    Hist_Node *node = (Hist_Node *)malloc(sizeof(Hist_Node));
    node->prev = NULL;
    node->next = NULL;
    strcpy(node->plane_id, plane_id);
    node->hist_kind = kind;
    return node;
}

void h_append(Hist_List *list, char plane_id[5], int kind)
{
    Hist_Node *node = create_hist_node(plane_id, kind);

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

void append(List *list, char plane_id[5])
{
    Node *node = create_node(plane_id);

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

void prepend(List *list, char plane_id[5])
{
    Node *node = create_node(plane_id);

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }

    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    list->size++;
}

char *dequeue(List *list)
{
    char *plane_id = (char *)malloc(sizeof(char[5]));
    strcpy(plane_id, list->head->plane_id);

    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return plane_id;
    }
    Node *aux = list->head->next;
    free(list->head);
    list->head = aux;
    list->head->prev = NULL;
    list->size--;

    return plane_id;
}

char *pop(List *list)
{
    char plane_id[5];
    strcpy(plane_id, list->tail->plane_id);

    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return plane_id;
    }
    Node *aux = list->tail->prev;
    free(list->tail);
    list->tail = aux;
    list->tail->next = NULL;
    list->size--;
    return plane_id;
}

void insert(List *list, char plane_id[5])
{
    if (list->head == NULL)
    {
        Node *node = create_node(plane_id);
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }

    if (strcmp(plane_id, list->head->plane_id) == -1)
    {
        prepend(list, plane_id);
        return;
    }

    if (strcmp(plane_id, list->tail->plane_id) == 1)
    {
        append(list, plane_id);
        return;
    }
    Node *node = create_node(plane_id);
    Node *aux = list->head->next;
    for (int i = 0; i < list->size; i++)
    {
        if (strcmp(plane_id, aux->plane_id) == 1)
        {
            node->next = aux;
            node->prev = aux->prev;
            aux->prev = node;
            node->prev->next = node;
            break;
        }
        aux = aux->next;
    }

    list->size++;
}

void _remove(List *list, char plane_id[5])
{
    Node *aux;
    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return plane_id;
    }
    if (strcmp(plane_id, list->head->plane_id) == 0)
    {
        aux = list->head;
        list->head = aux->next;
        list->head->prev = NULL;
        free(aux);
        list->size--;
        return;
    }

    if (strcmp(plane_id, list->tail->plane_id) == 0)
    {
        aux = list->tail;
        list->tail = aux->prev;
        list->tail->next = NULL;
        free(aux);
        list->size--;
        return;
    }

    aux = list->head;
    for (int i = 0; i < list->size; i++)
    {
        if (strcmp(plane_id, aux->plane_id) == 0)
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            list->size--;
            return;
        }
        aux = aux->next;
    }
}