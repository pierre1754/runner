/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

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
}
