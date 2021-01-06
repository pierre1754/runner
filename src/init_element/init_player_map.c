/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void init_map_elem(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;

    for (GET_MAP(engine)->map_adv;
        GET_MAP(engine)->map_adv < 20;
        GET_MAP(engine)->map_adv++) {
        for (int i = 0; i < SIZE_MAP; i++) {
            map_elem_1(i);
            place_player(i);
        }
    }
}
