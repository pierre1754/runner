/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void set_textures(int i, engine_t *engine)
{
    sfSprite_setTexture(GET_PARA(engine, par1_1 + i)->sprite,
                        GET_TEXTURE(engine, texPar1)->texture,
                        sfTrue);
    sfSprite_setTexture(GET_PARA(engine, par2_1 + i)->sprite,
                        GET_TEXTURE(engine, texPar2)->texture,
                        sfTrue);
    sfSprite_setTexture(GET_PARA(engine, par3_1 + i)->sprite,
                        GET_TEXTURE(engine, texPar3)->texture,
                        sfTrue);
}

static void create_para_sprite(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < parSize; i++) {
        GET_PARA(engine, i) = malloc(sizeof(parallax_t));
        GET_PARA(engine, i)->sprite = sfSprite_create();
        GET_PARA(engine, i)->pos = (sfVector2f){0};
        GET_PARA(engine, i)->speed = (sfVector2f){0};
    }
    sfSprite_setTexture(GET_PARA(engine, parColor)->sprite,
                        GET_TEXTURE(engine, texParStat)->texture,
                        sfTrue);
    for (int i = 0; i < 2; i++) {
        set_textures(i, engine);
    }
}

static void create_buttons(void)
{
    engine_t *engine = get_engine();

    GET_BUTTON(engine) = malloc(sizeof(buttons_t));
    GET_BUTTON(engine)->play_button = sfSprite_create();
    sfSprite_setTexture(GET_BUTTON(engine)->play_button,
                        GET_TEXTURE(engine, texPlay)->texture,
                        sfTrue);
    GET_BUTTON(engine)->pause_button = sfSprite_create();
    sfSprite_setTexture(GET_BUTTON(engine)->pause_button,
                        GET_TEXTURE(engine, texQuit)->texture,
                        sfTrue);
}

void create_environement(void)
{
    engine_t *engine = get_engine();

    GET_ENV(engine) = malloc(sizeof(environement_t));
    GET_SCORE(engine) = 0;
    create_para_sprite();
    create_buttons();
}
