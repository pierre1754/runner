/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include "my_runner.h"

char *get_str(int nbr)
{
    // int len = floor(log10(nbr)) + 1;
    char *result = malloc(sizeof(char) * 10);
    int rest = nbr;
    int temp;

    for (int i = 0; rest != 0; i++) {
        temp = rest % 10;
        rest /= 10;
        result[i] = temp + '0';
        result[i + 1] = '\0';
    }
    return my_revstr(result);
}