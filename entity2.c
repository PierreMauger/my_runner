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
    if (game->player->speed.y < 20)
        game->player->speed.y += 1;
    while (temp != NULL) {
        if (collide_tile(game, temp) == 1) {
            if (game->player->speed.y >= 0)
                game->player->speed.y = 0;
            game->player->pos.y = temp->pos.y - TILE_SIZE;
            game->player->jump = 1;
        }
        temp = temp->next;
    }
    sfSprite_move(game->player->sprite, game->player->speed);
}

int collide_tile(game_t *game, tile_t *tile)
{
    if (game->player->pos.y + PLAYER_HEIGHT > tile->pos.y &&
        game->player->pos.x < tile->pos.x + TILE_SIZE && game->player->pos.x +
        PLAYER_WIDTH > tile->pos.x)
        return 1;
    return 0;
}