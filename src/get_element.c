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

    if (engine->event.type == sfEvtKeyPressed ||
        engine->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW(engine));
}

void get_time(void)
{
    engine_t *engine = get_engine();

    GET_ELAPSED(engine) = sfTime_asSeconds(sfClock_restart(GET_CLOCK(engine)));
}

void get_image_pos(void)
{
    engine_t *engine = get_engine();

    for (int i = 1; i < parSize; i++) {
        GET_PARA(engine, i)->pos =
        sfSprite_getPosition(GET_PARA(engine, i)->sprite);
    }
}

void get_window_size(void)
{
    engine_t *engine = get_engine();

    GET_WINDOW_SIZE(engine) = sfRenderWindow_getSize(GET_WINDOW(engine));
}

void get_element(void)
{
    get_time();
    get_image_pos();
    get_window_size();
    // ADD
}
