/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** lib_func
*/

#include "my_runner.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int m = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[m + i] = src[i];
        dest[m + i + 1] = '\0';
    }
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    char *start = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char c;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        j--;
    }
    return str;
}

char *my_put_nbr(int nb)
{
    int i = nb;
    int j;
    char *res = malloc(5);

    res[0] = '0';
    res[1] = '\0';
    for (int c = 0; i != 0; c++) {
        j = i % 10;
        i = i / 10;
        res[c] = j + '0';
        res[c + 1] = '\0';
    }
    return my_revstr(res);
}
