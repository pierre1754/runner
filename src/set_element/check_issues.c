/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static bool check_win(void)
{
    engine_t *engine = get_engine();

    if (GET_ISSUE(engine).win) {
        sfRenderWindow_drawSprite(GET_WINDOW(engine),
                                GET_BUTTON(engine)->win_button,
                                NULL);
        return 1;
    }
    return 0;
}

static bool check_loose(void)
{
    engine_t *engine = get_engine();

    if (GET_ISSUE(engine).loose) {
        sfRenderWindow_drawSprite(GET_WINDOW(engine),
                                GET_BUTTON(engine)->loose_button,
                                NULL);
        return 1;
    }
    return 0;
}

static bool check_start(void)
{
    engine_t *engine = get_engine();

    if (GET_ISSUE(engine).start) {
        sfRenderWindow_drawSprite(GET_WINDOW(engine),
                                GET_BUTTON(engine)->play_button,
                                NULL);
        return 1;
    }
    return 0;
}

bool check_issues(void)
{
    engine_t *engine = get_engine();

    if (check_win() || check_loose() || check_start()) {
        sfRenderWindow_display(GET_WINDOW(engine));
        return 1;
    }
    return 0;
}