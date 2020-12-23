/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_bg(game_t *game)
{
    for (int i = 0; i < bgSize; i++)
        game->asset->array[i] = malloc(sizeof(parallax_t));
    game->asset->array[0]->texture = sfTexture_createFromFile("ressources/sky.png", NULL);
    game->asset->array[0]->sprite = sfSprite_create();
    game->asset->array[0]->speed = (sfVector2f){-1, 0};
    sfSprite_setTexture(game->asset->array[0]->sprite, game->asset->array[0]->texture, sfTrue);
    game->asset->array[1]->texture = sfTexture_createFromFile("ressources/city.png", NULL);
    game->asset->array[1]->sprite = sfSprite_create();
    game->asset->array[1]->speed = (sfVector2f){-5, 0};
    sfSprite_setTexture(game->asset->array[1]->sprite, game->asset->array[1]->texture, sfTrue);
}

void draw_bg(game_t *game)
{
    for (int i = 0; i < bgSize; i++) {
        sfRenderWindow_drawSprite(game->window, game->asset->array[i]->sprite, NULL);
        sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f){sfSprite_getPosition(game->asset->array[i]->sprite).x + game->w_size.width, 0});
        sfRenderWindow_drawSprite(game->window, game->asset->array[i]->sprite, NULL);
        sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f){sfSprite_getPosition(game->asset->array[i]->sprite).x - game->w_size.width, 0});
        if (-sfSprite_getPosition(game->asset->array[i]->sprite).x > game->w_size.width)
            sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f){0, 0});
    }
}

void update_bg(game_t *game)
{
    for (int i = 0; i < bgSize; i++)
        sfSprite_move(game->asset->array[i]->sprite,
        game->asset->array[i]->speed);
}