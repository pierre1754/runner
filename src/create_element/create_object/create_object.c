/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void create_player(void)
{
    engine_t *engine = get_engine();

    GET_PLAYER(engine) = malloc(sizeof(player_t));
    GET_PLAYER(engine)->sprite = sfSprite_create();
    sfSprite_setTexture(GET_PLAYER(engine)->sprite,
                        GET_TEXTURE(engine, texPlayer)->texture,
                        sfTrue);
    GET_PLAYER(engine)->pos = (sfVector2f){0};
    GET_PLAYER(engine)->speed = (sfVector2f){0};
    GET_PLAYER(engine)->jump = 0;
    GET_PLAYER(engine)->rect = GET_TEXTURE(engine, texPlayer)->rect_texture;
    sfSprite_setScale(GET_PLAYER(engine)->sprite,
                        (sfVector2f){3.0f, 3.0f});
}

static void create_map(void)
{
    engine_t *engine = get_engine();

    LIST_INIT(GET_HEAD(engine));
}

void create_object(void)
{
    engine_t *engine = get_engine();

    engine->object = malloc(sizeof(object_t));
    create_environement();
    create_player();
    create_map();
}
