/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static void check_window(void)
{
    engine_t *engine = get_engine();

    if (engine->event.key.code == sfKeyEscape ||
        engine->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW(engine));
}

static void check_jump(void)
{
    engine_t *engine = get_engine();

    if (engine->event.key.code == sfKeySpace &&
        GET_PLAYER(engine)->jump == 0) {
        GET_PLAYER(engine)->speed.y = -10;
        sfSound_play(GET_JUMP(engine));
        sfSprite_move(GET_PLAYER(engine)->sprite,
                    GET_PLAYER(engine)->speed);
    }
}

static void check_play(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));

    if (((GET_WINDOW_SIZE(engine).x / 2) - 206 < mouse.x &&
    mouse.x < (GET_WINDOW_SIZE(engine).x / 2) + 206) &&
    ((GET_WINDOW_SIZE(engine).y / 2) - 81 < mouse.y &&
    mouse.y < (GET_WINDOW_SIZE(engine).y / 2) + 81)) {
        GET_ISSUE(engine).start = 0;
        init_cursor(sfFalse);
    }
}

void get_event(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtMouseButtonPressed &&
    GET_ISSUE(engine).start) {
        check_play();
    }
    if (engine->event.type == sfEvtKeyPressed) {
        check_window();
        check_jump();
    }
}