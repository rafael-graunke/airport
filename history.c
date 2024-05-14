#include <stdlib.h>
#include <string.h>
#include "history.h"


History create_history()
{
    History list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

Record *create_record(char plane_id[5], int kind)
{
    Record *node = (Record *)malloc(sizeof(Record));
    node->prev = NULL;
    node->next = NULL;
    strcpy(node->plane_id, plane_id);
    node->hist_kind = kind;
    return node;
}

void h_append(History *list, char plane_id[5], int kind)
{
    Record *node = create_record(plane_id, kind);

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