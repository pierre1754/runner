/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

engine_t *get_engine(void)
{
    static engine_t *engine = NULL;

    if (!engine)
        engine = malloc(sizeof(engine_t));
    return engine;
}

void create_time(void)
{
    engine_t *engine = get_engine();

    engine->time = malloc(sizeof(time_elapsed_t));
    GET_CLOCK(engine) = sfClock_create();
}

void create_map_struct(void)
{
    engine_t *engine = get_engine();

    GET_MAP(engine) = malloc(sizeof(map_t));

    GET_MAP(engine)->map_adv = 0;
    GET_MAP(engine)->map_len = 0;
}

void create_engine(map_t *map)
{
    engine_t *engine = get_engine();

    GET_MAP(engine) = map;
    create_window();
    create_asset();
    create_object();
    create_time();
}
