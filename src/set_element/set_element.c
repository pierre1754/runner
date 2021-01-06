/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

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
    set_map_pos();
    set_player_pos();
}
