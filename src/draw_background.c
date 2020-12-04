/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void draw_background(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_drawSprite(GET_WINDOW(engine),
                            GET_OBJ_ENV_BACKGROUND_IMG(engine),
                            NULL);
}

void draw_plane_exp(void)
{
    engine_t *engine = get_engine();

    if (!GET_EXP_BOOL(engine))
        return;
    sfRenderWindow_drawSprite(GET_WINDOW(engine), GET_EXP_IMG(engine), NULL);
    if (GET_EXP_BOOL(engine) > 4)
        GET_EXP_BOOL(engine) = 0;
}
