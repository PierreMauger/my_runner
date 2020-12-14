/*
** EPITECH PROJECT, 2020
** Base
** File description:
** entity 2
*/

#include "my_runner.h"

void player_move(game_t *game)
{
    game->player->pos = sfSprite_getPosition(game->player->sprite);
    game->player->speed.y += 1;
    if (game->player->pos.y > 700 && game->player->speed.y > 0);
        game->player->speed.y = 0;
    sfSprite_move(game->player->sprite, game->player->speed);
    game->player->pos = sfSprite_getPosition(game->player->sprite);
    if (game->player->cooldown < 30)
        game->player->cooldown += 1;
}