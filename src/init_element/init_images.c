/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void image_scale(void)
{
    engine_t *engine = get_engine();

    sfSprite_setScale(GET_PARA(engine, parColor)->sprite,
                    (sfVector2f){5.0f, 5.0f});
    for (int i = 0; i < parSize; i++) {
        sfSprite_setScale(GET_PARA(engine, parColor + i)->sprite,
                        (sfVector2f){3.0f, 3.0f});
    }
}

void image_speed(void)
{
    engine_t *engine = get_engine();

    GET_PARA(engine, par1_1)->speed = (sfVector2f){-1500.0f, 0.0f};
    GET_PARA(engine, par1_2)->speed = (sfVector2f){-1500.0f, 0.0f};
    GET_PARA(engine, par2_1)->speed = (sfVector2f){-1000.0f, 0.0f};
    GET_PARA(engine, par2_2)->speed = (sfVector2f){-1000.0f, 0.0f};
    GET_PARA(engine, par3_1)->speed = (sfVector2f){-500.0f, 0.0f};
    GET_PARA(engine, par3_2)->speed = (sfVector2f){-500.0f, 0.0f};
}

void images_pos(void)
{
    engine_t *engine = get_engine();

    sfSprite_setPosition(GET_PARA(engine, par1_2)->sprite,
                        (sfVector2f){1776.0f, 0.0f});
    sfSprite_setPosition(GET_PARA(engine, par2_2)->sprite,
                        (sfVector2f){1776.0f, 0.0f});
    sfSprite_setPosition(GET_PARA(engine, par3_2)->sprite,
                        (sfVector2f){1776.0f, 0.0f});
}
