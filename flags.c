/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

int flag(char **av)
{
    if (av[1][0] != '-' || av[1][1] != 'h')
        return 84;
    write(0, "USAGES\n   ./my_runner asset/map/...\n\n", 37);
    write(0, "DECRIPTION\n  A finite runner game.\n", 35);
    write(0, "  Press 'Play' to launch the game.\n", 35);
    write(0, "  Press space bar to jump.\n", 27);
    write(0, "  To leave the game, press escape key or the exit ", 50);
    write(0, "button at the end of the game.\n", 31);
    return 0;
}
