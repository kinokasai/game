#include "id.hh"

int g_id;

void init_id_system()
{
    g_id = 0;
}

int new_id()
{
    g_id++;
    return g_id;
}
