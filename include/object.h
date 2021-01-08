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

#define GET_SCORE(engine) engine->object->env->score

#define GET_ENV(engine) engine->object->env
#define GET_PARA(engine, nbr) engine->object->env->parallax[nbr]
#define GET_BUTTON(engine) engine->object->env->buttons

#define GET_PLAYER(engine) engine->object->player

#define GET_HEAD(engine) &engine->object->map_elem

typedef enum {
    parColor,
    par1_1,
    par1_2,
    par2_1,
    par2_2,
    par3_1,
    par3_2,

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
    sfSprite *loose_button;
    sfSprite *win_button;
} buttons_t;

typedef struct {
    int score;
    sfFont *font;
    sfText *pt_score;
} score_t;

typedef struct {
    score_t *score;
    parallax_t *parallax[parSize];
    buttons_t *buttons;
} environement_t;

typedef struct {
    sfSprite *sprite;
    sfVector2f speed;
    sfVector2f pos;
    sfIntRect rect;
    bool jump;
} player_t;

typedef struct map_elem_s {
    sfSprite *sprite;
    sfVector2f speed;
    sfVector2f pos;
    LIST_ENTRY(map_elem_s) entries;
} map_elem_t;

typedef struct {
    environement_t *env;
    player_t *player;
    LIST_HEAD(, map_elem_s) map_elem;
} object_t;

void create_para_sprite(void);
void create_buttons(void);
void set_button_pos(void);
void create_text(void);
char *get_str(int nbr);
void create_environement(void);

map_elem_t *new_map_elem_1(void);
void create_object(void);
void destroy_object(void);

#endif // OBJECT_H
