/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

bool check_issues(void)
{
    engine_t *engine = get_engine();

    if (GET_ISSUE(engine).loose || GET_ISSUE(engine).win) {
        if (GET_ISSUE(engine).loose) {
            sfRenderWindow_drawSprite(GET_WINDOW(engine),
                                    GET_BUTTON(engine)->loose_button,
                                    NULL);
        }
        if (GET_ISSUE(engine).win) {
            sfRenderWindow_drawSprite(GET_WINDOW(engine),
                                    GET_BUTTON(engine)->win_button,
                                    NULL);
        }
        sfRenderWindow_display(GET_WINDOW(engine));
        return 1;
    }
    return 0;
}