/*
** EPITECH PROJECT, 2020
** Base
** File description:
** my_runner
*/

#include "my_runner.h"

void runner(char *buffer)
{
    game_t *game = malloc(sizeof(game_t));

    init_struct(game);
    load_map(game, buffer);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        if (game->state == MENU)
            menu_loop(game);
        if (game->state == PLAY)
            game_loop(game);
        if (game->state == GAME_OVER)
            over_loop(game, buffer);
        if (game->state == VICTORY)
            victory_loop(game, buffer);
    }
    destroy_all(game, buffer);
}