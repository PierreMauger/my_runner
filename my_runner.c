/*
** EPITECH PROJECT, 2020
** Base
** File description:
** my_runner
*/

#include "my_runner.h"

int change_bool(int value)
{
    if (value == 0)
        value = 1;
    else
        value = 0;
    return value;
}

void event_loop(game_t *game)
{
    tile_t *temp = game->tile;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed) {
            if (game->event.key.code == sfKeyP)
                game->game_pause = change_bool(game->game_pause);
            if (game->event.key.code == sfKeySpace && game->game_pause == 0 && game->player->cooldown == 30) {
                game->player->speed.y = -20;
                game->player->cooldown = 0;
            }
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void update_all(game_t *game)
{
    update_bg(game);
    move_tiles(game);
    anim_player(game);
    player_move(game);
}

void draw_all(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_bg(game);
    draw_text(game);
    draw_player(game);
    draw_map(game);
    sfRenderWindow_display(game->window);
}

void runner(char *buffer)
{
    game_t *game = malloc(sizeof(game_t));

    init_game(game);
    load_map(game, buffer);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    while (sfRenderWindow_isOpen(game->window)) {
        event_loop(game);
        if (game->game_pause == 0){
            update_all(game);
            draw_all(game);
        }
    }
    destroy_all(game, buffer);
}