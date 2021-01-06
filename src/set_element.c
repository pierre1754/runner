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

void set_sprite_loop(void)
{
    engine_t *engine = get_engine();
    static float sprite_refresh = 0;

    if (sprite_refresh > 0.02f) {
        GET_PLAYER(engine)->rect.left =
        (GET_PLAYER(engine)->rect.left + 24) % 144;
        sfSprite_setTextureRect(GET_PLAYER(engine)->sprite,
                                GET_PLAYER(engine)->rect);
        sprite_refresh = 0;
    }
    else sprite_refresh += GET_ELAPSED(engine);
}

void set_element(void)
{
    set_sprite_loop();
    set_map_elem();
    set_image_pos();
}
