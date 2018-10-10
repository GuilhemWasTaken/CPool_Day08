/*
** EPITECH PROJECT, 2018
** concat params
** File description:
** concate parameters 
*/

#include "my.h"
#include <stdlib.h>

static int param_len(int ac, char **av)
{
    int i = 0;
    int len = 0;

    while (i != ac) {
        len += (my_strlen(av[i]) + 1);
        i += 1;
    }
    return (len);
}

char *concat_params(int ac, char **av)
{
    char *dest = malloc(sizeof(char) * (param_len(ac, av) + 1));
    int i = 0;
    int a = 0;
    int k = 0;

    while (i != ac) {
        a = 0;
        while (av[i][a] != '\0') {
            dest[k] = av[i][a];
            k += 1;
            a += 1;
        }
        dest[k] = '\n';
        i += 1;
        k += 1;
    }
    dest[k] = '\0';
    return (dest);
}
