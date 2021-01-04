/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void set_image_pos(void)
{
    engine_t *engine = get_engine();

    for (int i = 1; i < parSize; i++) {
        sfSprite_move(GET_PARA(engine, i)->sprite,
        (sfVector2f){GET_PARA(engine, i)->speed.x * GET_ELAPSED(engine), 0.0f});
    }
}

void set_sprite_loop(void)
{
    engine_t *engine = get_engine();

    // GET_OBJ_ENV_CANON_REC(engine).left =
    // (GET_OBJ_ENV_CANON_REC(engine).left + 193) % 3667;
    // sfSprite_setTextureRect(GET_OBJ_ENV_CANON_EXP(engine),
    //                         GET_OBJ_ENV_CANON_REC(engine));
}

void set_element(void)
{
    set_image_pos();
}
