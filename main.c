/*
** EPITECH PROJECT, 2018
** main 
** File description:
** main
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    printf("%s\n", convert_base(av[1], av[2], av[3]));
}
