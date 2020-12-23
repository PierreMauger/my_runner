/*
** EPITECH PROJECT, 2020
** Include
** File description:
** my_hunter
*/

#ifndef RUNNER_H
#define RUNNER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct {
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    int cooldown;
} player_t;

typedef struct {
    sfFont *font;
    sfText *score_text;
    int score;
    char *str;
} text_t;

typedef enum {
    bgSky,
    bgCity,

    bgSize
} enum_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f speed;
} parallax_t;

typedef struct {
    parallax_t *array[bgSize];
} asset_t;

typedef struct tile {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    struct tile *next;
} tile_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
    sfEvent event;
    player_t *player;
    sfClock *clock;
    asset_t *asset;
    sfTime time;
    float seconds;
    text_t *text;
    int pause;
    tile_t *tile;
} game_t;

void move_rect(sfIntRect *rect, int offset, int max_offset);
void init_player(game_t *game);
void draw_player(game_t *game);
float anim_player(game_t *game);
void destroy_player(player_t *player);

void move_player(game_t *game);

sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void init_game(game_t *game);
void destroy_all(game_t *game, char *buffer);

int change_bool(int value);
void event_loop(game_t *game);
void update_all(game_t *game);
void draw_all(game_t *game);
void runner(char *buffer);

void init_bg(game_t *game);
void draw_bg(game_t *game);
void move_bg(game_t *game);

void init_text(game_t *game);
sfText *set_text(sfText *temp, text_t *text, sfColor color);
void draw_text(game_t *game);

void put_in_tile_list(tile_t **tile, sfVector2f pos, char *asset);
void draw_map(game_t *game);
void move_tiles(game_t *game);
void load_map(game_t *game, char *buffer);
void destroy_map(tile_t *tile);

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_put_nbr(int nb);

#endif
