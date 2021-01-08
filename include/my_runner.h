/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#ifndef MY_RUNNER_H
#define MY_RUNNER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#include "my.h"

#include "window.h"
#include "asset.h"
#include "object.h"

#define WIN_X 1280
#define WIN_Y 720

#define SIZE_MAP 12
#define LEN_MAP 100
#define IMAGE_SIZE 1776
#define MAP_SIZE 64
#define PLAYER_SIZE 81

#define MARGE MAP_SIZE - MAP_SIZE / 7

#define X_PLAYER GET_PLAYER(engine)->pos.x
#define Y_PLAYER GET_PLAYER(engine)->pos.y

#define GET_CLOCK(engine) (engine->time->clock)
#define GET_ELAPSED(engine) (engine->time->time_elapsed)

#define GET_MAP(engine) (engine->map)

#define GET_ISSUE(engine) (engine->issues)

typedef struct {
    sfClock *clock;
    float time_elapsed;
} time_elapsed_t;

typedef struct {
    char **map;
    int map_len;
    int map_adv;
} map_t;

typedef struct {
    bool win;
    bool loose;
} issues_t;

typedef struct {
    window_t *window;
    asset_t *asset;
    object_t *object;
    sfEvent event;
    time_elapsed_t *time;
    map_t *map;
    issues_t issues;
} engine_t;

int flag(char **av);
map_t *get_map(map_t *map, char *path);

engine_t *get_engine(void);

void create_issues_map(map_t *map);
void create_engine(map_t *map);

void set_textures(int i, engine_t *engine);
void place_player(int i);
void init_map_elem(void);
void init_cursor(void);
void init_music(void);
void image_scale(void);
void image_speed(void);
void images_pos(void);
void init_element(void);

void start_engine(void);

bool check_issues(void);
void get_event(void);
void get_time(void);
void get_image_pos(void);
void get_map_pos(void);
void get_player_pos(void);
void get_element(void);

void map_elem_1(int i);
void set_sprite_loop(void);
void set_image_pos(void);
void set_map_elem(void);
void set_player_pos(void);
void set_map_pos(void);
void set_score(void);
void set_element(void);

void draw_background(void);
void draw_map(void);
void draw_player(void);
void draw_element(void);

void destroy_engine(void);

#endif // MY_RUNNER_H
