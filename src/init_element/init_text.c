/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void init_text(void)
{
    engine_t *engine = get_engine();
    sfFont *font = sfFont_createFromFile("asset/pixelart.ttf");

    sfText_setFont(GET_SCORE(engine)->pt_score, font);
}