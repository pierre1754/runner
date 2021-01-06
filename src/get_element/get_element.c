/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void get_event(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtKeyPressed) {
        if (engine->event.key.code == sfKeyEscape ||
            engine->event.type == sfEvtClosed)
            sfRenderWindow_close(GET_WINDOW(engine));
        if (engine->event.key.code == sfKeySpace &&
            GET_PLAYER(engine)->jump == 0) {
            GET_PLAYER(engine)->speed.y = -10;
            sfSprite_move(GET_PLAYER(engine)->sprite,
                        GET_PLAYER(engine)->speed);
        }
    }
}

void get_time(void)
{
    engine_t *engine = get_engine();

    GET_ELAPSED(engine) = sfTime_asSeconds(sfClock_restart(GET_CLOCK(engine)));
}

void get_element(void)
{
    get_time();
    get_image_pos();
    get_map_pos();
    get_player_pos();
    // ADD
}
