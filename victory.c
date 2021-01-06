/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_vict(game_t *game)
{
    game->vict = malloc(sizeof(vict_t));
    game->vict->texture = sfTexture_createFromFile(VICTORY_IMG, NULL);
    game->vict->sprite = sfSprite_create();
    sfSprite_setTexture(game->vict->sprite, game->vict->texture, sfTrue);
    sfSprite_setPosition(game->vict->sprite, (sfVector2f){450, 300});
    game->vict->music = sfMusic_createFromFile(MUSIC_VICT);
}

void victory_loop(game_t *game, char *buffer)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyX)
            reset_game(game, game->vict->music, buffer, MENU);
        if (game->event.key.code == sfKeySpace)
            reset_game(game, game->vict->music, buffer, PLAY);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->vict->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void destroy_vict(vict_t *vict)
{
    sfTexture_destroy(vict->texture);
    sfSprite_destroy(vict->sprite);
    sfMusic_destroy(vict->music);
}
