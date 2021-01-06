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

    for (int i = 0; i < SIZE_MAP; i++) {
        map_elem_1(i);
    }
    if (GET_MAP(engine)->map_adv < GET_MAP(engine)->map_len - 1)
        GET_MAP(engine)->map_adv++;
}

void set_image_pos(void)
{
    engine_t *engine = get_engine();

    for (int i = 1; i < parSize; i++) {
        if (GET_PARA(engine, i)->pos.x < -IMAGE_SIZE) {
            sfSprite_setPosition(GET_PARA(engine, i)->sprite,
                                (sfVector2f)
                                {IMAGE_SIZE - IMAGE_SIZE / 15, -95.0f});
        }
        sfSprite_move(GET_PARA(engine, i)->sprite,
                    (sfVector2f){GET_PARA(engine, i)->speed.x *
                    GET_ELAPSED(engine), 0.0f});
    }
}

void set_map_pos(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;

    LIST_FOREACH(elem, GET_HEAD(engine), entries) {
        sfSprite_move(elem->sprite, (sfVector2f)
                    {elem->speed.x * GET_ELAPSED(engine), 0.0f});
    }
}