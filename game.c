/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my_runner.h"

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_runner",
    sfVideoMode_isValid(video_mode) ? sfDefaultStyle : sfClose, NULL);
    return (window);
}

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

void init_game(game_t *game)
{
    game->w_size = (sfVideoMode){1920, 1080, 32};
    game->window = create_my_window(game->w_size.width, game->w_size.height);
    game->asset = malloc(sizeof(asset_t));
    init_bg(game);
    game->data = malloc(sizeof(data_t));
    init_data(&game->data);
    game->clock = sfClock_create();
}

void destroy_all(game_t *game)
{
    //destroy_entity(game->entity);
    sfRenderWindow_destroy(game->window);
}