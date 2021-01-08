/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_getnbr
*/

#include "my_runner.h"

static int my_getneg(char const *s)
{
    int signe = 1;
    int change = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-' && change == 0)
            signe = signe * -1;
        if (s[i] != '-' && s[i] != '+')
            change = 1;
    }
    return (signe);
}

int my_getnbr(char const *s)
{
    long int result = 0;
    int signe = my_getneg(s);
    int change = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!(s[i] >= '0' && s[i] <= '9' || s[i] == '-' || s[i] == '+'))
            return (result * signe);
        else
            if (!(s[i] == '-' || s[i] == '+')) {
                change = 1;
                result = result * 10 + (s[i] - '0');
            }
            else if (change == 1)
                return (result * signe);
    }
    if (signe == -1)
        result = result * signe;
    if (result > 2147483647 || result < -2147483647)
        return (0);
    return (result);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return s1[i] - s2[i];
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}