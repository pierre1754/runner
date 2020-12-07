/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void create_para_sprite(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < parSize; i++) {
        malloc(sizeof(parallax_t));
        GET_PARA(engine, i)->sprite = sfSprite_create();
        sfSprite_setTexture(GET_PARA(engine, i)->sprite,
                        GET_TEXTURE(engine, i)->texture,
                        sfTrue);
        GET_PARA(engine, i)->pos = (sfVector2f){0};
        GET_PARA(engine, i)->speed = (sfVector2f){0};
    }
}

static void create_buttons(void)
{
    engine_t *engine = get_engine();

    GET_BUTTON(engine) = malloc(sizeof(buttons_t));
    GET_BUTTON(engine)->play_button = sfSprite_create();
    sfSprite_setTexture(GET_BUTTON(engine)->play_button,
                        GET_TEXTURE(engine, texPlay),
                        sfTrue);
    GET_BUTTON(engine)->pause_button = sfSprite_create();
    sfSprite_setTexture(GET_BUTTON(engine)->pause_button,
                        GET_TEXTURE(engine, texQuit),
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
