/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

map_elem_t *new_map_elem_1(void)
{
    engine_t *engine = get_engine();
    map_elem_t *new_elem = malloc(sizeof(map_elem_t));

    new_elem->speed = (sfVector2f){-550, 0};
    new_elem->pos = (sfVector2f){0};
    new_elem->sprite = sfSprite_create();
    sfSprite_setTexture(new_elem->sprite,
                        GET_TEXTURE(engine, texGround)->texture,
                        sfTrue);
    sfSprite_setScale(new_elem->sprite, (sfVector2f){0.125f, 0.125f});
    return new_elem;
}
