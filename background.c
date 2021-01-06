/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_bg(game_t *game)
{
    game->asset = malloc(sizeof(asset_t));
    for (int i = 0; i < bgSize; i++)
        game->asset->array[i] = malloc(sizeof(parallax_t));
    create_bg(game, 0, -1, SKY_IMG);
    create_bg(game, 1, -3, BACK_IMG);
    create_bg(game, 2, -5, MIDDLE_IMG);
    create_bg(game, 3, -7, FRONT_IMG);
}

void create_bg(game_t *game, int nb, int speed, char *img)
{
    game->asset->array[nb]->texture = sfTexture_createFromFile(img, NULL);
    game->asset->array[nb]->sprite = sfSprite_create();
    game->asset->array[nb]->speed = (sfVector2f){speed, 0};
    sfSprite_setTexture(game->asset->array[nb]->sprite,
    game->asset->array[nb]->texture, sfTrue);
}

void draw_bg(game_t *game)
{
    for (int i = 0; i < bgSize; i++) {
        sfRenderWindow_drawSprite(game->window,
        game->asset->array[i]->sprite, NULL);
        sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f)
        {sfSprite_getPosition(game->asset->array[i]->sprite).x +
        game->w_size.width, 0});
        sfRenderWindow_drawSprite(game->window,
        game->asset->array[i]->sprite, NULL);
        sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f)
        {sfSprite_getPosition(game->asset->array[i]->sprite).x -
        game->w_size.width, 0});
        if (-sfSprite_getPosition(game->asset->array[i]->sprite).x >
        game->w_size.width)
            sfSprite_setPosition(game->asset->array[i]->sprite,
            (sfVector2f){0, 0});
    }
}

void move_bg(game_t *game)
{
    for (int i = 0; i < bgSize; i++)
        sfSprite_move(game->asset->array[i]->sprite,
        game->asset->array[i]->speed);
}