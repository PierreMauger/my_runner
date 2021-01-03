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
    game->over->music = sfMusic_createFromFile(MUSIC_MENU);
}

void over_loop(game_t *game, char *buffer)
{
    if (game->over->opacity < 255)
        game->over->opacity++;
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyX && game->over->opacity == 255)
            go_to_menu(game);
        if (game->event.key.code == sfKeySpace && game->over->opacity == 255)
            reset_game(game, game->over->music, buffer);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    sfSprite_setColor(game->over->sprite, sfColor_fromRGBA(255, 255, 255,
    game->over->opacity));
    sfRenderWindow_drawSprite(game->window, game->over->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void reset_game(game_t *game, sfMusic *old_source, char *buffer)
{
    change_music(old_source, game->music);
    game->over->opacity = 0;
    sfSprite_setPosition(game->player->sprite, (sfVector2f){200, 400});
    game->tile = NULL;
    load_map(game, buffer);
    game->enemy = NULL;
    spawn_entity(game);
    game->text->score = 0;
    game->player->jump = 1;
    game->state = PLAY;
}

void destroy_over(over_t *over)
{
    sfTexture_destroy(over->texture);
    sfSprite_destroy(over->sprite);
    sfMusic_destroy(over->music);
}