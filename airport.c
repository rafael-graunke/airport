#include "airport.h"
#include "history.h"
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
    airport.hist = create_history();

    return airport;
}

int get_key(char plane_id[5])
{
    return plane_id[0] - 'A';
}

bool check_plane(Airport *airport, char plane_id[5])
{
    List list = airport->ldisp[get_key(plane_id)];
    return contains(&list, plane_id);
}

bool insert_plane(Airport *airport, char plane_id[5])
{
    if (check_plane(airport, plane_id))
        return false;

    insert(&(airport->ldisp[get_key(plane_id)]), plane_id);
    return true;
}

bool remove_plane(Airport *airport, char plane_id[5])
{
    if (!check_plane(airport, plane_id))
        return false;
    delete (&(airport->ldisp[get_key(plane_id)]), plane_id);
    return true;
}

bool queue_liftoff(Airport *airport, char plane_id[5])
{
    List *ldisp = &(airport->ldisp[get_key(plane_id)]);

    if (!contains(ldisp, plane_id))
        return false;

    if (contains(&(airport->fate), plane_id))
        return false;

    if (contains(&(airport->fdec), plane_id))
        return true;

    append(&(airport->fdec), plane_id);
    return true;
}

char *dequeue_liftoff(Airport *airport)
{
    if (airport->fdec.size)
    {
        char *plane_id = dequeue(&(airport->fdec));
        h_append(&(airport->hist), plane_id, 1);
        return plane_id;
    }
    return NULL;
}

bool queue_landing(Airport *airport, char plane_id[5])
{
    List *ldisp = &(airport->ldisp[get_key(plane_id)]);

    if (!contains(ldisp, plane_id))
        return false;

    if (contains(&(airport->fdec), plane_id))
        return false;

    if (contains(&(airport->fate), plane_id))
        return true;

    append(&(airport->fate), plane_id);
    return true;
}

char *dequeue_landing(Airport *airport)
{
    if (airport->fate.size)
    {
        char *plane_id = dequeue(&(airport->fate));
        h_append(&(airport->hist), plane_id, 0);
        return plane_id;
    }
    return NULL;
}