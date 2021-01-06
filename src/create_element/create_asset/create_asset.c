/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void create_sounds(void)
{
    engine_t *engine = get_engine();

    engine->asset->sounds = malloc(sizeof(sounds_t));

    GET_BUF_JUMP(engine) = sfSoundBuffer_createFromFile("asset/jump.ogg");
    GET_JUMP(engine) = sfSound_create();
    sfSound_setBuffer(GET_JUMP(engine), GET_BUF_JUMP(engine));
}

void create_asset(void)
{
    engine_t *engine = get_engine();

    engine->asset = malloc(sizeof(asset_t));
    GET_MUSIC(engine) = sfMusic_createFromFile("asset/music.ogg");
    create_sounds();
    create_textures();
}
