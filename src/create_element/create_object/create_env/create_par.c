/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void set_textures(int i, engine_t *engine)
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

void create_para_sprite(void)
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
