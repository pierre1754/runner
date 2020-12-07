/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/queue.h>

typedef enum {
    // ADD PARALLAX HERE

    parSize
} parallax_list_t;

typedef struct {
    sfVector2f speed;
    sfVector2f pos;
    sfSprite *sprite;
} parallax_t;

typedef struct {
    sfSprite *play_button;
    sfSprite *pause_button;
} buttons_t;

typedef struct {
    size_t score;
    parallax_list_t *parallax[parSize];
    buttons_t *buttons;
} environement_t;

typedef struct {
    sfSprite *sprite;
    sfVector2f speed;
    sfVector2f pos;
} player_t;

typedef struct map_elem_s {
    sfSprite *sprite;
    sfIntRect rect_sprite;
    sfVector2f speed;
    sfVector2f pos;
    LIST_ENTRY(map_elem_t) entries;
} map_elem_t;

typedef struct {
    environement_t *env;
    player_t *player;
    LIST_HEAD(, map_elem_s) map_elem;
} object_t;

void create_object(void);
void destroy_object(void);

#endif // OBJECT_H
