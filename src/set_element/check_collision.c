/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static int high_block(map_elem_t *elem, int hit)
{
    engine_t *engine = get_engine();
    int x = elem->pos.x - X_PLAYER;
    int y = (elem->pos.y - 3) - Y_PLAYER;
    bool hit_x = x > 0 && x < MAP_SIZE;
    bool hit_y = y > 0 && y < MAP_SIZE;

    if (hit_x && hit_y) {
        GET_PLAYER(engine)->speed.y = 0;
        GET_PLAYER(engine)->jump = 0;
        hit++;
    }
    return hit;
}

static int bottom_block(map_elem_t *elem, int hit)
{
    engine_t *engine = get_engine();
    int x = elem->pos.x - X_PLAYER;
    int y = Y_PLAYER - elem->pos.y;
    bool hit_x = x > 0 && x < MAP_SIZE;
    bool hit_y = y > -10 && y < MAP_SIZE;

    if (hit_x && hit_y) {
        GET_PLAYER(engine)->speed.y *= -1;
    }
    return hit;
}

static void left_block(map_elem_t *elem)
{
    engine_t *engine = get_engine();
    int x = X_PLAYER - elem->pos.x;
    int y = Y_PLAYER - (elem->pos.y - MAP_SIZE + MARGE);
    bool hit_x = x >= 0 && x <= MAP_SIZE;
    bool hit_y = y >= 0 && y <= MAP_SIZE;

    if (hit_x && hit_y) {
        GET_ISSUE(engine).loose = 1;
    }
}

void set_player_pos(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;
    int hit = 0;

    LIST_FOREACH(elem, GET_HEAD(engine), entries) {
        hit = high_block(elem, hit);
        hit = bottom_block(elem, hit);
        left_block(elem);
    }
    if (!hit) {
        GET_PLAYER(engine)->jump = 1;
        GET_PLAYER(engine)->speed.y += GET_ELAPSED(engine) * 20;
    }
    sfSprite_move(GET_PLAYER(engine)->sprite, GET_PLAYER(engine)->speed);
}
