/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void create_buttons(void)
{
    engine_t *engine = get_engine();

    GET_BUTTON(engine) = malloc(sizeof(buttons_t));
    GET_BUTTON(engine)->play_button = sfSprite_create();
    GET_BUTTON(engine)->pause_button = sfSprite_create();
    GET_BUTTON(engine)->loose_button = sfSprite_create();
    GET_BUTTON(engine)->win_button = sfSprite_create();
    sfSprite_setTexture(GET_BUTTON(engine)->play_button,
                        GET_TEXTURE(engine, texPlay)->texture,
                        sfTrue);
    sfSprite_setTexture(GET_BUTTON(engine)->pause_button,
                        GET_TEXTURE(engine, texQuit)->texture,
                        sfTrue);
    sfSprite_setTexture(GET_BUTTON(engine)->loose_button,
                        GET_TEXTURE(engine, texLoose)->texture,
                        sfTrue);
    sfSprite_setTexture(GET_BUTTON(engine)->win_button,
                        GET_TEXTURE(engine, texWin)->texture,
                        sfTrue);
}

void set_button_pos(void)
{
    engine_t *engine = get_engine();

    sfSprite_setPosition(GET_BUTTON(engine)->loose_button,
                    (sfVector2f){(GET_WINDOW_SIZE(engine).x / 2) - 270, 0});
    sfSprite_setPosition(GET_BUTTON(engine)->win_button,
                    (sfVector2f){(GET_WINDOW_SIZE(engine).x / 2) - 270, 0});
}

void create_text(void)
{
    engine_t *engine = get_engine();

    GET_SCORE(engine) = malloc(sizeof(score_t));
    GET_SCORE(engine)->score = 0;
    GET_SCORE(engine)->font = sfFont_createFromFile("asset/pixelart.ttf");
    GET_SCORE(engine)->pt_score = sfText_create();
}

void create_environement(void)
{
    engine_t *engine = get_engine();

    GET_ENV(engine) = malloc(sizeof(environement_t));
    create_text();
    create_para_sprite();
    create_buttons();
    set_button_pos();
}
