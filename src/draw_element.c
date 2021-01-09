/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void draw_map(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;

    LIST_FOREACH(elem, GET_HEAD(engine), entries) {
        sfRenderWindow_drawSprite(GET_WINDOW(engine), elem->sprite, NULL);
    }
}

void draw_background(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_drawSprite(GET_WINDOW(engine),
                            GET_PARA(engine, parColor)->sprite,
                            NULL);
    for (int i = parSize - 1; i > 0; i--) {
        sfRenderWindow_drawSprite(GET_WINDOW(engine),
                                GET_PARA(engine, parColor + i)->sprite,
                                NULL);
    }
}

void draw_player(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_drawSprite(GET_WINDOW(engine),
                            GET_PLAYER(engine)->sprite,
                            NULL);
}

void draw_score(void)
{
    engine_t *engine = get_engine();

    sfText_setString(GET_SCORE(engine)->pt_score,
                    get_str(GET_SCORE(engine)->score));
    sfRenderWindow_drawText(GET_WINDOW(engine),
                    GET_SCORE(engine)->pt_score, NULL);
}

void draw_element(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_clear(GET_WINDOW(engine), sfBlack);
    draw_background();
    draw_map();
    draw_score();
    draw_player();
    sfRenderWindow_display(GET_WINDOW(engine));
}
