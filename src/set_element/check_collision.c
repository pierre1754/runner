/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static int check_collision(map_elem_t *elem, int hit)
{
    engine_t *engine = get_engine();
    bool x = 0;
    bool y = 0;

    x = GET_PLAYER(engine)->pos.x >= elem->pos.x &&
        GET_PLAYER(engine)->pos.x <= (elem->pos.x + MAP_SIZE);
    y = GET_PLAYER(engine)->pos.y >= elem->pos.y - MAP_SIZE;
        if (y && x) {
            GET_PLAYER(engine)->speed.y = 0;
            GET_PLAYER(engine)->jump = 0;
            hit++;
        }
        if (x && (GET_PLAYER(engine)->pos.y > elem->pos.y - (MAP_SIZE - MAP_SIZE / 5)));
            // ADD LOOSE BUTTON
        else if (x && (GET_PLAYER(engine)->pos.y > elem->pos.y - MAP_SIZE)) {
            GET_PLAYER(engine)->speed.y = (elem->pos.y - MAP_SIZE) -
                                        (GET_PLAYER(engine)->pos.y);
        }
    return hit;
}

void set_player_pos(void)
{
    engine_t *engine = get_engine();
    map_elem_t *elem;
    int hit = 0;

    LIST_FOREACH(elem, GET_HEAD(engine), entries) {
        hit = check_collision(elem, hit);
    }
    if (!hit) {
        GET_PLAYER(engine)->jump = 1;
        GET_PLAYER(engine)->speed.y += GET_ELAPSED(engine) * 20;
    }
    sfSprite_move(GET_PLAYER(engine)->sprite, GET_PLAYER(engine)->speed);
}
