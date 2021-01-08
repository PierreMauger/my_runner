/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void init_over(game_t *game)
{
    game->over = malloc(sizeof(over_t));
    game->over->texture = sfTexture_createFromFile(GAMEOVER_IMG, NULL);
    game->over->sprite = sfSprite_create();
    sfSprite_setTexture(game->over->sprite, game->over->texture, sfTrue);
    sfSprite_setPosition(game->over->sprite, (sfVector2f){450, 300});
    game->over->opacity = 0;
    game->over->tinfo = sfTexture_createFromFile(OVER_INFO_IMG, NULL);
    game->over->sinfo = sfSprite_create();
    sfSprite_setTexture(game->over->sinfo, game->over->tinfo, sfTrue);
    sfSprite_setPosition(game->over->sinfo, (sfVector2f){660, 750});
    game->over->info_op = 10;
    game->over->info_add = 2;
    game->over->music = sfMusic_createFromFile(MUSIC_OVER);
}

void over_draw(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_text(game);
    sfSprite_setColor(game->over->sprite, sfColor_fromRGBA(255, 255, 255,
    game->over->opacity));
    sfRenderWindow_drawSprite(game->window, game->over->sprite, NULL);
    if (game->over->opacity == 254) {
        sfSprite_setColor(game->over->sinfo, sfColor_fromRGBA(255, 255, 255,
        game->over->info_op));
        sfRenderWindow_drawSprite(game->window, game->over->sinfo, NULL);
    }
    sfRenderWindow_display(game->window);
}

void over_loop(game_t *game, char *buffer)
{
    if (game->over->opacity < 254)
        game->over->opacity += 2;
    if (game->over->info_op < 2 || game->over->info_op > 253)
        game->over->info_add *= -1;
    game->over->info_op += game->over->info_add;
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyX && game->over->opacity == 254)
            reset_game(game, game->over->music, buffer, MENU);
        if (game->event.key.code == sfKeySpace && game->over->opacity == 254)
            reset_game(game, game->over->music, buffer, PLAY);
    }
    over_draw(game);
}

void reset_game(game_t *game, sfMusic *old_source, char *buffer, int dest)
{
    if (dest == MENU)
        change_music(old_source, game->menu->music);
    else
        change_music(old_source, game->music);
    sfText_setPosition(game->text->score_text, (sfVector2f){100, 100});
    sfText_setColor(game->text->score_text, sfBlack);
    sfSprite_setPosition(game->player->sprite, (sfVector2f){200, 400});
    game->tile = NULL;
    load_map(game, buffer);
    game->enemy = NULL;
    spawn_entity(game);
    game->over->opacity = 0;
    game->vict->opacity = 0;
    game->text->score = 0;
    game->player->jump = 1;
    game->state = dest;
}

void destroy_over(over_t *over)
{
    sfTexture_destroy(over->texture);
    sfSprite_destroy(over->sprite);
    sfMusic_destroy(over->music);
}