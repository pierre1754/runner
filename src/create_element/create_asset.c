/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void create_sounds(void)
{
    engine_t *engine = get_engine();

    engine->asset->sounds = malloc(sizeof(sounds_t));

    GET_BUF_JUMP(engine) = sfSoundBuffer_createFromFile("asset/jump.ogg");
    GET_JUMP(engine) = sfSound_create();
    sfSound_setBuffer(GET_JUMP(engine), GET_BUF_JUMP(engine));
}

static void create_parallax(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < PARA_NBR; i++) {
        malloc(sizeof(textures_t));
        GET_TEXTURE(engine, i)->rect_texture = (sfIntRect){0};
    }
    GET_TEXTURE(engine, texParStat)->texture =
    sfTexture_createFromFile("asset/par_notmov.png", NULL);
    GET_TEXTURE(engine, texPar1)->texture =
    sfTexture_createFromFile("asset/par_first.png", NULL);
    GET_TEXTURE(engine, texPar2)->texture =
    sfTexture_createFromFile("asset/par_second.png", NULL);
    GET_TEXTURE(engine, texPar3)->texture =
    sfTexture_createFromFile("asset/par_last.png", NULL);
    GET_TEXTURE(engine, texPlay)->texture =
    sfTexture_createFromFile("asset/play.png", NULL);
    GET_TEXTURE(engine, texQuit)->texture =
    sfTexture_createFromFile("asset/quit.png", NULL);
}

static void create_textures(void)
{
    engine_t *engine = get_engine();

    create_parallax();
}

void create_asset(void)
{
    engine_t *engine = get_engine();

    GET_MUSIC(engine) = sfMusic_createFromFile("asset/music.ogg");
    create_sounds();
    create_textures();
}
