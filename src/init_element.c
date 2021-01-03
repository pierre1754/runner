/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void init_cursor(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_setMouseCursorVisible(GET_WINDOW(engine), sfFalse);
}

static void init_music(void)
{
    engine_t *engine = get_engine();

    sfMusic_play(GET_MUSIC(engine));
    sfMusic_setLoop(GET_MUSIC(engine), sfTrue);
}

static void image_scale(void)
{
    engine_t *engine = get_engine();

    sfSprite_setScale(GET_PARA(engine, parColor)->sprite,
                    (sfVector2f){5.0f, 5.0f});
    for (int i = 0; i < parSize; i++) {
        sfSprite_setScale(GET_PARA(engine, parColor + i)->sprite,
                        (sfVector2f){3.0f, 3.0f});
    }
}

void init_element(void)
{
    init_cursor();
    init_music();
    image_scale();
    // ADD
}
