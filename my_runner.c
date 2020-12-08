/*
** EPITECH PROJECT, 2020
** Base
** File description:
** my_runner
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "include/my_runner.h"

void event_loop(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void draw_bg(game_t *game)
{
    for (int i = 0; i < bgSize; i++) {
        sfSprite_move(game->asset->array[i]->sprite, game->asset->array[i]->speed);
        sfRenderWindow_drawSprite(game->window, game->asset->array[i]->sprite, NULL);
        sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f){sfSprite_getPosition(game->asset->array[i]->sprite).x + game->w_size.width, 0});
        sfRenderWindow_drawSprite(game->window, game->asset->array[i]->sprite, NULL);
        sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f){sfSprite_getPosition(game->asset->array[i]->sprite).x - game->w_size.width, 0});
        if (-sfSprite_getPosition(game->asset->array[i]->sprite).x > game->w_size.width)
            sfSprite_setPosition(game->asset->array[i]->sprite, (sfVector2f){0, 0});
    }
}

void runner(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_game(game);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        event_loop(game);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_bg(game);
        draw_text(game);
        sfRenderWindow_display(game->window);
        game->data->score += 1;
    }
    destroy_all(game);
}