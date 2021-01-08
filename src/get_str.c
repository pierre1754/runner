/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include "my_runner.h"

char *get_str(int nbr)
{
    int nbr_len = floor(log10(abs(nbr))) + 1;
    char *result = malloc(sizeof(char) * (nbr_len + 1));
    int temp_nbr = 0;

    for (int i = nbr_len; i > 0; i--) {
        temp_nbr = nbr % my_compute_power_rec(10, i);
        result[nbr_len - i] = temp_nbr + '0';
    }
    result[nbr_len] = '\0';
    return result;
}