/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_menu(game_t *game)
{
    game->menu = malloc(sizeof(menu_t));
    game->menu->texture = sfTexture_createFromFile(SKY_IMG, NULL);
    game->menu->sprite = sfSprite_create();
    sfSprite_setTexture(game->menu->sprite, game->menu->texture, sfTrue);
    game->menu->music = sfMusic_createFromFile(MUSIC_MENU);
    sfMusic_play(game->menu->music);
    sfMusic_setLoop(game->menu->music, 1);
}

void menu_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeySpace) {
            sfMusic_stop(game->menu->music);
            game->state = PLAY;
        }
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->menu->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void destroy_menu(menu_t *menu)
{
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->sprite);
    sfMusic_destroy(menu->music);
}
