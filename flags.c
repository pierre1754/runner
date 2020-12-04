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
    write(0, "USAGES\n   ./my_hunter $(MAP_PATH)\n\n", 35);
    write(0, "DECRIPTION\n   A infinite run game.\n", 35);
    return 0;
}
