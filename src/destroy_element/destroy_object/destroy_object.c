/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

void destroy_object(void)
{
    engine_t *engine = get_engine();

    destroy_environement();
    free(engine->object);
}
