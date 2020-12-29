/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_menu(game_t *game)
{
    game->menu->texture = sfTexture_createFromFile(SKY_IMG, NULL);
    game->menu->sprite = sfSprite_create();
    sfSprite_setTexture(game->menu->sprite, game->menu->texture, sfTrue);
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