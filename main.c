/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "my_runner.h"

int main(int argc, char **argv)
{
    struct stat file = {0};
    int a = stat(argv[1], &file);
    int fd = open(argv[1], O_RDONLY);
    char *buffer = malloc(sizeof(char) * file.st_size + 1);
    int b = read(fd, buffer, file.st_size);

    if (argc != 2)
        return 84;
    buffer[file.st_size] = '\0';
    runner(buffer);
    close(fd);
    return 0;
}