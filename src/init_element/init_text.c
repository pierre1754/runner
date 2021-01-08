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

    sfText_setFont(GET_SCORE(engine)->pt_score, GET_SCORE(engine)->font);
    sfText_setColor(GET_SCORE(engine)->pt_score, sfBlack);
    sfText_setCharacterSize(GET_SCORE(engine)->pt_score, 50);
    sfText_setPosition(GET_SCORE(engine)->pt_score, (sfVector2f){10, 0});
}