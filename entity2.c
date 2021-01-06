/*
** EPITECH PROJECT, 2020
** Base
** File description:
** entity 2
*/

#include "my_runner.h"

void check_all_collide(game_t *game, tile_t *temp)
{
    if (collide_side(game, temp)) {
        change_music(game->music, game->over->music);
        game->state = GAME_OVER;
    }
    else
        if (collide_tile(game, temp)) {
            if (game->player->speed.y != JUMP_HEIGHT + 1)
                game->player->speed.y = 0;
            game->player->pos.y = temp->pos.y - PLAYER_HEIGHT;
            game->player->jump = 1;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
}

void move_player(game_t *game)
{
    tile_t *temp = game->tile;
    enemy_t *hits = game->enemy;

    game->player->pos = sfSprite_getPosition(game->player->sprite);
    if (game->player->speed.y < 30)
        game->player->speed.y += 1;
    while (temp != NULL) {
        check_all_collide(game, temp);
        temp = temp->next;
    }
    while (hits != NULL) {
        if (collide_hits(game, hits)) {
            change_music(game->music, game->over->music);
            game->state = GAME_OVER;
        }
        hits = hits->next;
    }
    sfSprite_move(game->player->sprite, game->player->speed);
}

int collide_tile(game_t *game, tile_t *tile)
{
    if (game->player->pos.y + PLAYER_HEIGHT >= tile->pos.y &&
        game->player->pos.x < tile->pos.x + TILE_SIZE && game->player->pos.x +
        PLAYER_WIDTH > tile->pos.x && tile->solid == 1)
        return 1;
    return 0;
}

int collide_side(game_t *game, tile_t *tile)
{
    if (game->player->pos.x + PLAYER_WIDTH > tile->pos.x && game->player->pos.x
        < tile->pos.x + TILE_SIZE && game->player->pos.y < tile->pos.y +
        TILE_SIZE && game->player->pos.y + PLAYER_HEIGHT > tile->pos.y + 30 &&
        tile->solid == 1)
        return 1;
    return 0;
}

int collide_hits(game_t *game, enemy_t *tile)
{
    if (game->player->pos.x + PLAYER_WIDTH > tile->pos.x && game->player->pos.x
        < tile->pos.x + ENEMY_WIDTH && game->player->pos.y < tile->pos.y +
        ENEMY_HEIGHT && game->player->pos.y + PLAYER_HEIGHT > tile->pos.y)
        return 1;
    return 0;
}