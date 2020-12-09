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

void init_game(game_t *game)
{
    game->w_size = (sfVideoMode){1920, 1080, 32};
    game->window = create_my_window(game->w_size.width, game->w_size.height);
    game->asset = malloc(sizeof(asset_t));
    init_bg(game);
    game->text = malloc(sizeof(text_t));
    init_text(&game->text);
    game->clock = sfClock_create();
    game->game_pause = 0;
}

void destroy_all(game_t *game)
{
    //destroy_entity(game->entity);
    sfRenderWindow_destroy(game->window);
}