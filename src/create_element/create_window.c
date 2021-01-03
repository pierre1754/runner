/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void create_window(void)
{
    engine_t *engine = get_engine();
    sfVideoMode mode = {1776, 816, 32};

    engine->window = malloc(sizeof(window_t));
    GET_WINDOW(engine) = sfRenderWindow_create(mode,
                                            "My Runner",
                                            sfClose,
                                            NULL);
    sfRenderWindow_setVerticalSyncEnabled(GET_WINDOW(engine), sfTrue);
    GET_WINDOW_SIZE(engine) = (sfVector2f) {mode.width, mode.height};
}
