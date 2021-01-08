/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "my_runner.h"

static void print_h(void)
{
    my_putstr("Last version of the runner, a CFSML project\n\nUSAGE:\n");
    my_putstr("./my_runner ressources/[map]\n\nLEVELS:\n\tmap1\n\tmap2\n\n");
    my_putstr("OPTION:\n-h\tprint the usage and quit\n\nUSER_INTERACTIONS:\n");
    my_putstr("In game\n\tSpace: Jump/Double Jump\n\tP: Pause/Play\nIn menu");
    my_putstr("\n\tX: Go to menu\n\tSpace: Restart\n");
}

int main(int argc, char **argv)
{
    struct stat file = {0};
    int stat_err = stat(argv[1], &file);
    int fd = open(argv[1], O_RDONLY);
    char *buffer = malloc(sizeof(char) * file.st_size + 1);
    int read_err = read(fd, buffer, file.st_size);

    buffer[file.st_size] = '\0';
    if (argc != 2)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        print_h();
    else {
        if (fd == -1 || read_err == -1 || stat_err != 0 || file.st_size == 0)
            return 84;
        else
            runner(buffer);
    }
    close(fd);
    return 0;
}