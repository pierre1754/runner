/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void create_button(void)
{
    engine_t *engine = get_engine();

    GET_TEXTURE(engine, texPlay)->texture =
    sfTexture_createFromFile("asset/play.png", NULL);
    GET_TEXTURE(engine, texQuit)->texture =
    sfTexture_createFromFile("asset/quit.png", NULL);
    GET_TEXTURE(engine, texLoose)->texture =
    sfTexture_createFromFile("asset/game_over.png", NULL);
    GET_TEXTURE(engine, texWin)->texture =
    sfTexture_createFromFile("asset/win.jpeg", NULL);
    GET_TEXTURE(engine, texGround)->texture =
    sfTexture_createFromFile("asset/dirt.jpeg", NULL);
}

void create_text_para(void)
{
    engine_t *engine = get_engine();

    GET_TEXTURE(engine, texParStat)->texture =
    sfTexture_createFromFile("asset/par_notmov.png", NULL);
    GET_TEXTURE(engine, texPar1)->texture =
    sfTexture_createFromFile("asset/par_first.png", NULL);
    GET_TEXTURE(engine, texPar2)->texture =
    sfTexture_createFromFile("asset/par_second.png", NULL);
    GET_TEXTURE(engine, texPar3)->texture =
    sfTexture_createFromFile("asset/par_last.png", NULL);
}

void create_text_sprite(void)
{
    engine_t *engine = get_engine();

    GET_TEXTURE(engine, texPlayer)->texture =
    sfTexture_createFromFile("asset/player_run.png", NULL);
    GET_TEXTURE(engine, texPlayer)->rect_texture = (sfIntRect){0, 0, 24, 24};
}

void create_textures(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < texSize; i++) {
        GET_TEXTURE(engine, i) = malloc(sizeof(textures_t));
        GET_TEXTURE(engine, i)->rect_texture = (sfIntRect){0};
    }
    create_button();
    create_text_para();
    create_text_sprite();
}