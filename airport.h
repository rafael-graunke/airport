#include <stdbool.h>
#include "list.h"

#ifndef _AIRPORT_H
#define _AIRPORT_H


typedef struct s_airport {
    List ldisp[26];
    List fdec;
    List fate;
} Airport;

Airport create_airport();
bool insert_plane(Airport *airport, char plane_id[5]);
bool queue_liftoff(Airport *airport, char plane_id[5]);
bool queue_landing(Airport *airport, char plane_id[5]);
bool check_plane(Airport *airport, char plane_id[5]);

#endif