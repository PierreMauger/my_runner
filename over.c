/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_over(game_t *game)
{
    game->over->texture = sfTexture_createFromFile(CITY_IMG, NULL);
    game->over->sprite = sfSprite_create();
    sfSprite_setTexture(game->over->sprite, game->over->texture, sfTrue);
    game->over->opacity = 0;
}

void over_loop(game_t *game, char *buffer)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyX)
            game->state = MENU;
        if (game->event.key.code == sfKeySpace)
            reset_game(game, buffer);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->over->opacity < 255)
        game->over->opacity++;
    sfSprite_setColor(game->over->sprite, sfColor_fromRGBA(255, 255, 255,
    game->over->opacity));
    sfRenderWindow_drawSprite(game->window, game->over->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void reset_game(game_t *game, char *buffer)
{
    game->over->opacity = 0;
    sfSprite_setPosition(game->player->sprite, (sfVector2f){200, 620});
    game->tile = NULL;
    load_map(game, buffer);
    game->text->score = 0;
    game->state = PLAY;
}
