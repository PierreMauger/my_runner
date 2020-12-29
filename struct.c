/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

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

void init_struct(game_t *game)
{
    game->w_size = (sfVideoMode){1920, 1080, 32};
    game->window = create_my_window(game->w_size.width, game->w_size.height);
    game->asset = malloc(sizeof(asset_t));
    init_bg(game);
    game->text = malloc(sizeof(text_t));
    init_text(game);
    game->clock = sfClock_create();
    game->pause = 0;
    game->player = malloc(sizeof(player_t));
    init_player(game);
    game->tile = NULL;
    game->state = MAIN_MENU;
    game->menu = malloc(sizeof(menu_t));
    init_menu(game);
}

void destroy_all(game_t *game, char *buffer)
{
    free(buffer);
    destroy_player(game->player);
    destroy_map(game->tile);
    sfRenderWindow_destroy(game->window);
}