/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

int main(int argc, char **argv)
{
    if (argc > 2 || argc < 2)
        return 84;
    if (argv[1][0] == '-')
        return flag(argv);
    create_engine();
    // init_element();
    // start_engine();
    // destroy_engine();
    return 0;
}
