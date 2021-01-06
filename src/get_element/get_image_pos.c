/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void get_image_pos(void)
{
    engine_t *engine = get_engine();

    for (int i = 1; i < parSize; i++) {
        GET_PARA(engine, i)->pos =
        sfSprite_getPosition(GET_PARA(engine, i)->sprite);
    }
}

void get_map_pos(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;

    LIST_FOREACH(elem, GET_HEAD(engine), entries) {
        elem->pos = sfSprite_getPosition(elem->sprite);
    }
}

void get_player_pos(void)
{
    engine_t *engine = get_engine();

    GET_PLAYER(engine)->pos = sfSprite_getPosition(GET_PLAYER(engine)->sprite);
}
