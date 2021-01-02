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
    game->music = sfMusic_createFromFile(MUSIC_MENU);
    init_bg(game);
    init_text(game);
    init_player(game);
    init_menu(game);
    init_over(game);
    init_vict(game);
    game->clock = sfClock_create();
    game->pause = 0;
    game->tile = NULL;
    game->enemy = NULL;
    game->state = MENU;
}

void destroy_all(game_t *game, char *buffer)
{
    free(buffer);
    sfMusic_destroy(game->music);
    destroy_player(game->player);
    destroy_enemy(game->enemy);
    destroy_map(game->tile);
    destroy_menu(game->menu);
    destroy_over(game->over);
    destroy_vict(game->vict);
    sfRenderWindow_destroy(game->window);
}