/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_vict(game_t *game)
{
    game->vict = malloc(sizeof(vict_t));
    game->vict->texture = sfTexture_createFromFile(CITY_IMG, NULL);
    game->vict->sprite = sfSprite_create();
    sfSprite_setTexture(game->vict->sprite, game->vict->texture, sfTrue);
}

void victory_loop(game_t *game, char *buffer)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyX)
            game->state = MENU;
        if (game->event.key.code == sfKeySpace)
            reset_game(game, buffer);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->vict->sprite, NULL);
    sfRenderWindow_display(game->window);
}