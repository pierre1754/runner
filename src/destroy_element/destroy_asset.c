/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void destroy_sounds(void)
{
    engine_t *engine = get_engine();

    sfSound_destroy(GET_JUMP(engine));
    sfSoundBuffer_destroy(GET_BUF_JUMP(engine));
    free(engine->asset->sounds);
}

static void destroy_textures(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < texSize; i++) {
        sfTexture_destroy(GET_TEXTURE(engine, i));
        free(engine->asset->textures[i]);
    }
}

void destroy_asset(void)
{
    engine_t *engine = get_engine();

    sfMusic_destroy(GET_MUSIC(engine));
    destroy_sounds();
    destroy_textures();
    free(engine->asset);
}
