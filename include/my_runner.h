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
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "my.h"

#include "window.h"
#include "asset.h"
#include "object.h"

#define WIN_X 1280
#define WIN_Y 720

#define SIZE_MAP 10
#define IMAGE_SIZE 1776

#define GET_CLOCK(engine) (engine->time->clock)
#define GET_ELAPSED(engine) (engine->time->time_elapsed)

#define GET_MAP(engine) (engine->map)

typedef struct {
    sfClock *clock;
    float time_elapsed;
} time_elapsed_t;

typedef struct {
    char **map;
    int map_adv;
} map_t;

typedef struct {
    window_t *window;
    asset_t *asset;
    object_t *object;
    sfEvent event;
    time_elapsed_t *time;
    map_t *map;
} engine_t;

int flag(char **av);
char **get_map(char *path);

engine_t *get_engine(void);

void create_map_struct(char **map);
void create_engine(char **map);

void init_cursor(void);
void init_music(void);
void image_scale(void);
void image_speed(void);
void images_pos(void);
void init_element(void);

void start_engine(void);

void get_event(void);
void get_time(void);
void get_image_pos(void);
void get_element(void);

void set_map_elem(void);
void set_image_pos(void);
void set_element(void);

void draw_background(void);
void draw_element(void);

void destroy_engine(void);

#endif // MY_RUNNER_H
