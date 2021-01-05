/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#define GET_WINDOW(engine) (engine->window->window)
#define GET_WINDOW_SIZE(engine) (engine->window->window_size)

typedef struct {
    sfRenderWindow *window;
    sfVector2u window_size;
} window_t;

void create_window(void);
void get_window_size(void);
void destroy_window(void);

#endif // WINDOW_H
