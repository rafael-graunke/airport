#include "airport.h"
#include "list.h"

#include <stdio.h>

Airport create_airport()
{
    Airport airport;
    for (int i = 0; i < 26; i++)
    {
        airport.ldisp[i] = create_list();
    }
    airport.fate = create_list();
    airport.fdec = create_list();
    airport.hist = create_list();

    return airport;
}

bool check_plane(Airport *airport, char plane_id[5])
{
    int key = plane_id[0] - 'A';
    List list = airport->ldisp[key];
    return contains(&list, plane_id);
}

bool insert_plane(Airport *airport, char plane_id[5])
{
    int key = plane_id[0] - 'A';
    List *list = &(*airport).ldisp[key];
    if (contains(list, plane_id))
    {
        return 0;
    }
    insert(list, plane_id);
    return 1;
}

bool queue_liftoff(Airport *airport, char plane_id[5])
{
    int key = plane_id[0] - 'A';
    List *ldisp = &(*airport).ldisp[key];
    if (!contains(ldisp, plane_id))
    {
        return 0;
    }
    List *list = &(*airport).fdec;
    if (contains(list, plane_id))
    {
        return 1;
    }
    append(list, plane_id);
    return 1;
}

char *dequeue_liftoff(Airport *airport)
{
    List *list = &(*airport).fdec;
    if ((*list).size > 0)
    {
        char *plane_id = dequeue(list);
        return plane_id;
    }
    return NULL;
}

bool queue_landing(Airport *airport, char plane_id[5])
{
    int key = plane_id[0] - 'A';
    List *ldisp = &(*airport).ldisp[key];
    if (!contains(ldisp, plane_id))
    {
        return 0;
    }
    List *list = &(*airport).fate;
    if (contains(list, plane_id))
    {
        return 1;
    }
    append(list, plane_id);
    return 1;
}

char *dequeue_landing(Airport *airport)
{
    List *list = &(*airport).fate;
    if ((*list).size > 0)
    {
        char *plane_id = dequeue(list);
        return plane_id;
    }
    return NULL;
}