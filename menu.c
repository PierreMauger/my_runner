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