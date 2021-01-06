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

#define MENU 0
#define PLAY 1
#define GAME_OVER 2
#define VICTORY 3
#define JUMP_HEIGHT -25
#define TILE_SIZE 80
#define PLAYER_HEIGHT 160
#define PLAYER_WIDTH 92
#define ENEMY_HEIGHT 68
#define ENEMY_WIDTH 128
#define NB_ANIM_E 2
#define NB_ANIM_P 8
#define ANIME_TIME 0.12
#define PLAYER_IMG "ressources/run_sprite.png"
#define ENEMY_IMG "ressources/missile.png"
#define DIRT_IMG "ressources/dirt.png"
#define GRASS_IMG "ressources/grass.png"
#define BACK_IMG "ressources/city_back.png"
#define MIDDLE_IMG "ressources/city_middle.png"
#define FRONT_IMG "ressources/city_front.png"
#define SKY_IMG "ressources/sky.png"
#define GAMEOVER_IMG "ressources/gameover.png"
#define VICTORY_IMG "ressources/victory.png"
#define PLAYER_SOUND "ressources/jump.ogg"
#define MUSIC_MENU "ressources/music_menu.ogg"
#define MUSIC_VICT "ressources/music_vict.ogg"
#define MUSIC_OVER "ressources/music_over.ogg"

typedef struct {
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfSoundBuffer *buffer;
    sfSound *sound;
    int jump;
} player_t;

typedef struct enemy {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    struct enemy *next;
} enemy_t;

typedef struct {
    sfFont *font;
    sfText *score_text;
    int score;
    char *str;
} text_t;

typedef enum {
    bgSky,
    bgCityBack,
    bgCityMiddle,
    bgCityFront,
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
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    struct tile *next;
} tile_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic *music;
    //sprite_button
} menu_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    int opacity;
    sfMusic *music;
    //sound
    //sprite_button
} over_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic *music;
    //sound
    //sprite_button
} vict_t;

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
    sfEvent event;
    player_t *player;
    enemy_t *enemy;
    sfMusic *music;
    sfClock *clock;
    asset_t *asset;
    sfTime time;
    float seconds;
    text_t *text;
    int pause;
    tile_t *tile;
    int state;
    menu_t *menu;
    over_t *over;
    vict_t *vict;
    int map_size;
} game_t;

void move_rect(sfIntRect *rect, int offset, int max_offset);
void init_player(game_t *game);
void draw_player(game_t *game);
float anim_player(game_t *game);
void destroy_player(player_t *player);

void move_player(game_t *game);
void check_all_collide(game_t *game, tile_t *temp);
int collide_tile(game_t *game, tile_t *tile);
int collide_side(game_t *game, tile_t *tile);
int collide_hits(game_t *game, enemy_t *tile);

sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void init_struct(game_t *game);
void destroy_all(game_t *game, char *buffer);

void change_music(sfMusic *old_source, sfMusic *new_source);
void runner(char *buffer);

void init_bg(game_t *game);
void create_bg(game_t *game, int nb, int speed, char *img);
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
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_put_nbr(int nb);
int my_getnbr(char const *s);

int change_bool(int value);
void event_loop(game_t *game);
void update_all(game_t *game);
void draw_all(game_t *game);
void game_loop(game_t *game);

void init_over(game_t *game);
void over_loop(game_t *game, char *buffer);
void reset_game(game_t *game, sfMusic *old_source, char *buffer, int dest);
void destroy_over(over_t *over);

void init_menu(game_t *game);
void menu_loop(game_t *game);
void destroy_menu(menu_t *menu);
void go_to_menu(game_t *game);

void init_vict(game_t *game);
void victory_loop(game_t *game, char *buffer);
void destroy_vict(vict_t *vict);

void put_in_enemy_list(enemy_t **enemy, sfVector2f pos, char *asset);
void spawn_entity(game_t *game);
void draw_enemy(game_t *game);
void move_enemy(game_t *game);
void destroy_enemy(enemy_t *enemy);

#endif
