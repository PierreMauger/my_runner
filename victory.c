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
    game->vict->opacity = 0;
    game->vict->tinfo = sfTexture_createFromFile(VICT_INFO_IMG, NULL);
    game->vict->sinfo = sfSprite_create();
    sfSprite_setTexture(game->vict->sinfo, game->vict->tinfo, sfTrue);
    sfSprite_setPosition(game->vict->sinfo, (sfVector2f){660, 750});
    game->vict->info_op = 10;
    game->vict->info_add = 2;
    game->vict->music = sfMusic_createFromFile(MUSIC_VICT);
}

void victory_draw(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_text(game);
    sfSprite_setColor(game->vict->sprite, sfColor_fromRGBA(255, 255, 255,
    game->vict->opacity));
    sfRenderWindow_drawSprite(game->window, game->vict->sprite, NULL);
    if (game->vict->opacity == 254) {
        sfSprite_setColor(game->vict->sinfo, sfColor_fromRGBA(255, 255, 255,
        game->vict->info_op));
        sfRenderWindow_drawSprite(game->window, game->vict->sinfo, NULL);
    }
    sfRenderWindow_display(game->window);
}

void victory_loop(game_t *game, char *buffer)
{
    if (game->vict->opacity < 254)
        game->vict->opacity += 2;
    if (game->vict->info_op < 2 || game->vict->info_op > 253)
        game->vict->info_add *= -1;
    game->vict->info_op += game->vict->info_add;
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyX && game->vict->opacity == 254)
            reset_game(game, game->vict->music, buffer, MENU);
        if (game->event.key.code == sfKeySpace && game->vict->opacity == 254)
            reset_game(game, game->vict->music, buffer, PLAY);
    }
    victory_draw(game);
}

void destroy_vict(vict_t *vict)
{
    sfTexture_destroy(vict->texture);
    sfSprite_destroy(vict->sprite);
    sfMusic_destroy(vict->music);
}
