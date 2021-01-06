/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void map_elem_1(int i)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;

    if (GET_MAP(engine)->map[i][GET_MAP(engine)->map_adv] == '1') {
        elem = new_map_elem_1();
        elem->pos = (sfVector2f){GET_MAP(engine)->map_adv * MAP_SIZE,
                                i * MAP_SIZE};
        sfSprite_setPosition(elem->sprite, elem->pos);
        LIST_INSERT_HEAD(GET_HEAD(engine), elem, entries);
    }
}

void place_player(int i)
{
    engine_t *engine = get_engine();

    if (GET_MAP(engine)->map[i][GET_MAP(engine)->map_adv] == '2') {
        GET_PLAYER(engine)->pos = (sfVector2f)
                                {GET_MAP(engine)->map_adv * MAP_SIZE,
                                (i + 1) * MAP_SIZE};
        sfSprite_setPosition(GET_PLAYER(engine)->sprite,
                            GET_PLAYER(engine)->pos);
    }
}
