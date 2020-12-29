/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "my_runner.h"

void game_loop(game_t *game)
{
    event_loop(game);
    if (game->pause == 0){
        update_all(game);
        draw_all(game);
    }
}

void menu_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeySpace)
            game->state = PLAY;
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->menu->sprite, NULL);
    sfRenderWindow_display(game->window);
}