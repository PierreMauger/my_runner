/*
** EPITECH PROJECT, 2020
** Base
** File description:
** entity 2
*/

#include "my_runner.h"

void move_player(game_t *game)
{
    tile_t *temp = game->tile;

    game->player->pos = sfSprite_getPosition(game->player->sprite);
    game->player->speed.y += 1;
    while (temp != NULL) {
        if (game->player->pos.y + PLAYER_HEIGHT > temp->pos.y &&
        game->player->pos.x < temp->pos.x + TILE_SIZE && game->player->pos.x +
        PLAYER_WIDTH > temp->pos.x && game->player->cooldown != 0) {
            game->player->speed.y = 0;
            game->player->cooldown = MAX_COOLDOWN;
        }
        temp = temp->next;
    }
    sfSprite_move(game->player->sprite, game->player->speed);
    game->player->pos = sfSprite_getPosition(game->player->sprite);
    if (game->player->cooldown < MAX_COOLDOWN)
        game->player->cooldown += 1;
}