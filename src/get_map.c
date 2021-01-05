/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static char **init_array(int len_line)
{
    int size = 10;
    char **array = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i <= size; i++) {
        array[i] = malloc(sizeof(char *) * (len_line));
        memset(array[i], ' ', len_line - 1);
        array[i][len_line - 1] = '\0';
    }
    array[size] = NULL;
    return array;
}

static int verif_map(char *file)
{
    for (int i = 0; file[i]; i++) {
        if ((file[i] < '1' || file[i] > '1') &&
            file[i] != '\n' &&
            file[i] != ' ') {
            return 1;
        }
    }
    return 0;
}

int get_len(char *file)
{
    int max_len = 0;
    int actual_len = 0;

    for (int i = 0; file[i]; i++) {
        actual_len++;
        if (file[i] == '\n') {
            if (max_len < actual_len)
                max_len = actual_len;
            actual_len = 0;
        }
    }
    return max_len;
}

char **my_str_to_line_array(char const *file, int lines, int bytes)
{
    int size = 10;
    char **map = init_array(lines);
    int adv = 0;
    int act_line = 0;

    if (file == 0)
        return 0;
    for (int tab_nbr = 0; tab_nbr < size; tab_nbr++) {
        if (adv >= bytes)
            return map;
        for (; file[adv + act_line] != '\n'; act_line++);
        map[tab_nbr] = my_strncpy(map[tab_nbr], (file + adv), act_line);
        act_line++;
        adv += act_line;
        act_line = 0;
    }
    return map;
}

char **get_map(char *path)
{
    struct stat size = {0};
    int fd = open(path, O_RDONLY);
    char *file = NULL;

    if (fd == -1 || stat(path, &size) == -1 || !size.st_size)
        return NULL;
    file = malloc(sizeof(char) * (size.st_size + 1));
    memset(file, '\0', size.st_size + 1);
    read(fd, file, size.st_size);
    if (verif_map(file))
        return NULL;
    return my_str_to_line_array(file, get_len(file), size.st_size);
}
