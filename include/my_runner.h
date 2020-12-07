/*
** EPITECH PROJECT, 2020
** Include
** File description:
** my_hunter
*/

#ifndef RUNNER_H
#define RUNNER_H

typedef struct entity {
    char *name;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    struct entity *next;
} entity_t;

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

typedef struct {
    sfRenderWindow *window;
    sfVideoMode w_size;
    sfEvent event;
    entity_t *entity;
    sfClock *clock;
    asset_t *asset;
    sfTime time;
    float seconds;
} game_t;

void move_rect(sfIntRect *rect, int offset, int max_offset);
void create_entity(entity_t **list, sfVideoMode w_size);
void draw_entity(entity_t *entity, sfRenderWindow *window);
float anim_entity(game_t *game);
void destroy_entity(entity_t *entity);

sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
void init_game(game_t *game);
void init_bg(game_t *game);
void destroy_all(game_t *game);

void event_loop(game_t *game);
void runner(void);

#endif
