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
    map_elem_t *elem;

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

void set_player_pos(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;
    int hit = 0;

    LIST_FOREACH(elem, GET_HEAD(engine), entries) {
        if (GET_PLAYER(engine)->pos.y >= elem->pos.y - 64) {
            GET_PLAYER(engine)->speed.y = 0;
            GET_PLAYER(engine)->jump = 0;
            hit++;
        }
    }
    if (!hit) {
        GET_PLAYER(engine)->jump = 1;
        GET_PLAYER(engine)->speed.y += GET_ELAPSED(engine) * 20;
    }
    sfSprite_move(GET_PLAYER(engine)->sprite, GET_PLAYER(engine)->speed);
}
