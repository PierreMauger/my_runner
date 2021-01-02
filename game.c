/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
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
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed) {
            if (game->event.key.code == sfKeyP)
                game->pause = change_bool(game->pause);
            if (game->event.key.code == sfKeySpace && game->pause == 0 &&
            game->player->jump == 1) {
                game->player->speed.y = JUMP_HEIGHT;
                game->player->jump = 0;
                sfSound_play(game->player->sound);
            }
        }
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void update_all(game_t *game)
{
    move_bg(game);
    move_tiles(game);
    anim_player(game);
    move_player(game);
    game->text->score += 1;
    if (game->tile->pos.x + TILE_SIZE < 200) {
        change_music(game->music, game->vict->music);
        game->state = VICTORY;
    }
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

void game_loop(game_t *game)
{
    event_loop(game);
    if (game->pause == 0) {
        update_all(game);
        draw_all(game);
    }
}
