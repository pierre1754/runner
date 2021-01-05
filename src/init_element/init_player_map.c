/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"



void set_map_elem(void)
{
    engine_t *engine = get_engine();
    bool player = 0;
    map_elem_t *elem;

    for (int i = 0; i < SIZE_MAP; i++) {
        if (GET_MAP(engine)->map[i][GET_MAP(engine)->map_adv] == '1') {
            elem = new_map_elem_1();
            elem->pos = (sfVector2f){GET_MAP(engine)->map_adv *
                                    MAP_SIZE, i * MAP_SIZE};
            sfSprite_setPosition(elem->sprite, elem->pos);
            LIST_INSERT_HEAD(GET_HEAD(engine), elem, entries);
        }
        if (GET_MAP(engine)->map[i][GET_MAP(engine)->map_adv] == '2' &&
            !player) {
            GET_PLAYER(engine)->pos = (sfVector2f){GET_MAP(engine)->map_adv *
                                                MAP_SIZE, (i + 1) * MAP_SIZE};
            sfSprite_setPosition(GET_PLAYER(engine)->sprite, GET_PLAYER(engine)->pos);
            player++;
        }
    }
    if (GET_MAP(engine)->map_adv < 20)
        GET_MAP(engine)->map_adv++;
}
