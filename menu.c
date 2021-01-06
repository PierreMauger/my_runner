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
    game->menu->tinfo = sfTexture_createFromFile(MENU_INFO_IMG, NULL);
    game->menu->sinfo = sfSprite_create();
    sfSprite_setTexture(game->menu->sinfo, game->menu->tinfo, sfTrue);
    sfSprite_setPosition(game->menu->sinfo, (sfVector2f){750, 750});
    game->menu->info_op = 10;
    game->menu->info_add = 2;
    sfMusic_play(game->menu->music);
    sfMusic_setLoop(game->menu->music, 1);
}

void menu_draw(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->menu->sprite, NULL);
    sfSprite_setColor(game->menu->sinfo, sfColor_fromRGBA(255, 255, 255,
    game->menu->info_op));
    sfRenderWindow_drawSprite(game->window, game->menu->sinfo, NULL);
    sfRenderWindow_display(game->window);
}

void menu_loop(game_t *game)
{
    if (game->menu->info_op < 2 || game->menu->info_op > 253)
        game->menu->info_add *= -1;
    game->menu->info_op += game->menu->info_add;
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeySpace) {
            sfMusic_stop(game->menu->music);
            change_music(game->menu->music, game->music);
            game->state = PLAY;
        }
    }
    menu_draw(game);
}

void destroy_menu(menu_t *menu)
{
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->sprite);
    sfMusic_destroy(menu->music);
}
