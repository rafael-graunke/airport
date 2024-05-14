#include <stdbool.h>
#ifndef _HISTORY_H
#define _HISTORY_H

typedef struct s_record
{
    struct s_record *prev;
    struct s_record *next;
    char plane_id[5];
    int hist_kind; //  0 - aterrisar 1 - decolar
} Record;

typedef struct s_history
{
    Record *head;
    Record *tail;
    int size;
} History;

History create_history();
Record *create_record(char plane_id[5], int kind);
void h_append(History *list, char plane_id[5], int kind);

#endif