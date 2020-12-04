/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** 05/10/2020
*/

#include "my.h"

char *my_revstr(char *str)
{
    int incr = 0;
    int len = my_strlen(str);
    char cp_str[len + 1];

    len--;
    my_strcpy(cp_str, str);
    for (;len >= 0 && str[incr]; len--, incr++)
        str[incr] = cp_str[len];
    str[incr + 1] = '\0';
    return (str);
}
