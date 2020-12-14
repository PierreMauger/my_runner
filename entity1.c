/*
** EPITECH PROJECT, 2020
** Base
** File description:
** entity 1
*/

#include "my_runner.h"

void move_rect(sfIntRect *rect, int offset, int max_offset)
{
    rect->left += offset;
    if (rect->left >= max_offset)
        rect->left = 0;
}

void init_player(game_t *game)
{
    game->player->speed = (sfVector2f){0, 0};
    game->player->pos = (sfVector2f){200, 620};
    game->player->rect = (sfIntRect){0, 0, 120, 114};
    game->player->texture = (sfTexture *)sfTexture_createFromFile
    ("ressources/pidgey.png", NULL);
    game->player->sprite = (sfSprite *)sfSprite_create();
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    game->player->cooldown = 30;
}

void draw_player(game_t *game)
{
    sfSprite_setTexture(game->player->sprite, game->player->texture, sfTrue);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    sfSprite_move(game->player->sprite, game->player->speed);
}

float anim_player(game_t *game)
{
    player_t *temp = game->player;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > 0.2) {
        move_rect(&temp->rect, 120, 480);
        sfClock_restart(game->clock);
    }
    return game->seconds;
}

void destroy_player(player_t *player)
{
    sfTexture_destroy(player->texture);
    sfSprite_destroy(player->sprite);
}
