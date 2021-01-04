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

static void image_speed(void)
{
    engine_t *engine = get_engine();

    GET_PARA(engine, par1_1)->speed = (sfVector2f){-300.0f, 0.0f};
    GET_PARA(engine, par1_2)->speed = (sfVector2f){-300.0f, 0.0f};
    GET_PARA(engine, par2_1)->speed = (sfVector2f){-200.0f, 0.0f};
    GET_PARA(engine, par2_2)->speed = (sfVector2f){-200.0f, 0.0f};
    GET_PARA(engine, par3_1)->speed = (sfVector2f){-100.0f, 0.0f};
    GET_PARA(engine, par3_2)->speed = (sfVector2f){-100.0f, 0.0f};
}

void init_element(void)
{
    init_cursor();
    init_music();
    image_scale();
    image_speed();
    // ADD
}
