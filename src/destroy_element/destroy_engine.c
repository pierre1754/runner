/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void destroy_time(void)
{
    engine_t *engine = get_engine();

    sfClock_destroy(GET_CLOCK(engine));
    free(engine->time);
}

void destroy_engine(void)
{
    destroy_window();
    destroy_asset();
    destroy_time();
}
    // destroy_object();
