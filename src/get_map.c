/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_runner.h"

static char **init_array(void)
{
    int size = 10;
    char **array = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i <= size; i++)
        array[i] = NULL;
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
    printf("%d\n", max_len);
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
    get_len(file);
    // return my_str_to_line_array(file, );
}

// char **my_str_to_line_array(char const *str, int lines, int nbr_char)
// {
//     map_t *map = malloc(sizeof(map_t));
//     int adv = 0;

//     if (str == 0 || count_lines(map, str, lines))
//         return 0;
//     map->x = colon(str);
//     map->map = init_array(lines);
//     for (int tab_nbr = 0; tab_nbr < lines; tab_nbr++) {
//         if (adv >= nbr_char)
//             return map;
//         map->map[tab_nbr] = my_strndup((str + adv), map->x);
//             for (; str[adv] != '\n'; adv++);
//         adv++;
//     }
//     map->map[map->y] = NULL;
//     return map;
// }
