/*
** EPITECH PROJECT, 2018
** convert base
** File description:
** convert a int base
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

static int check_base_form(char const *nbr, char const *base_form, int mul)
{
    int n = (mul == -1) ? 1 : 0;
    int bf = 0;
    int ret = 0;

    while (nbr[n] != '\0') {
        bf = 0;
        ret = 0;
        while (base_form[bf] != '\0') {
            ret += (nbr[n] != base_form[bf]) ? 1 : 0;
            bf += 1;
        }
        if (ret == my_strlen(base_form))
            return (0);
        n += 1;
    }
    return (1);
}

static int value_unit_nbr(char const *nbr, int i, char const *base_form)
{
    int k = 0;

    while (base_form[k] != '\0') {
        if (nbr[i] == base_form[k])
            return (k);
        k += 1;
    }
    return (0);
}

static int convert_decimal(int res, char const *nbr, char const *base_form, int mul)
{
    int nbr_len = my_strlen(nbr);
    int power = 1;
    int i = nbr_len - 1;
    int min = (mul == -1) ? -1 : 0;

    while (i >= min) {
        res += value_unit_nbr(nbr, i, base_form) * power;
        power = power * my_strlen(base_form);
        i -= 1;
    }
    return (res);
}

static char *nbrbase_to_string(int res, char const *base_to, int mul, int mal)
{
    int mal_max = (mul == 1) ? mal + 1 : mal + 2;
    char *ret = malloc(sizeof(char) * mal_max);
    int i = mal_max - 2;
    int bt_len = my_strlen(base_to);

    if (mul == -1)
        ret[0] = '-';
    while (res > 0) {
        ret[i] = base_to[res % bt_len];
        res /= bt_len;
        i -= 1;
    }
    ret[mal_max - 1] = '\0';
    return (ret);
}

char *convert_base(char const *nbr, char const *base_form, char const *base_to)
{
    char *ret;
    int res = 0;
    int mul = (nbr[0] == '-') ? -1 : 1;
    int mal = 0;

    if (check_base_form(nbr, base_form, mul) == 0)
        return (my_strdup("Error, nbr isn't in the right base_form.\n"));
    res = convert_decimal(res, nbr, base_form, mul);
    my_putnbr_base(res, base_to);
    my_putchar('\n');
    if (res == 0)
        return (my_strdup("0"));
    while (res != 0) {
        mal += 1;
        res /= 10;
    }
    res = convert_decimal(res, nbr, base_form, mul);
    return (nbrbase_to_string(res, base_to, mul, mal));
}
