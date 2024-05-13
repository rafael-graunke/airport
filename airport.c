#include "airport.h"
#include "list.h"

Airport create_airport()
{
    Airport airport;
    for (int i = 0; i < 26; i++)
    {
        airport.ldisp[i] = create_list();
    }
    airport.fate = create_list();
    airport.fdec = create_list();

    return airport;
}

bool check_plane(Airport *airport, char plane_id[5])
{
    int key = plane_id[0] - 'A';
    List list = airport->ldisp[key];
    return contains(&list, plane_id);
}

void insert_plane(Airport *airport, char plane_id[5])
{
    int key = plane_id[0] - 'A';
    List list = airport->ldisp[key];
    insert(&list, plane_id);
}

void queue_liftoff(Airport *airport, char plane_id[5])
{
    queue(&airport->fdec, plane_id);
}

void queue_landing(Airport *airport, char plane_id[5])
{
    queue(&airport->fate, plane_id);
}
