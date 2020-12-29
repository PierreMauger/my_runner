/*
** EPITECH PROJECT, 2020
** Base
** File description:
** game
*/

#include "my_runner.h"

void put_in_tile_list(tile_t **tile, sfVector2f pos, char *asset)
{
    tile_t *element = malloc(sizeof(tile_t));

    element->pos = pos;
    element->texture = sfTexture_createFromFile(asset, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, element->pos);
    element->next = *tile;
    *tile = element;
}

void draw_map(game_t *game)
{
    tile_t *temp = game->tile;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        temp = temp->next;
    }
}

void move_tiles(game_t *game)
{
    tile_t *temp = game->tile;

    while (temp != NULL) {
        sfSprite_move(temp->sprite, (sfVector2f){-9, 0});
        temp->pos = sfSprite_getPosition(temp->sprite);
        temp = temp->next;
    }
}

void load_map(game_t *game, char *buffer)
{
    int line = 0;

    game->map_size = my_getnbr(buffer);
    for (int i = 0; buffer[i + 4] != '\0'; i++) {
        if (buffer[i + 4] == '\n')
            line += 1;
        if (buffer[i + 4] == '0')
            put_in_tile_list(&game->tile, (sfVector2f){i * TILE_SIZE - line *
            TILE_SIZE * game->map_size, line * TILE_SIZE}, GRASS_IMG);
        if (buffer[i + 4] == '1')
            put_in_tile_list(&game->tile, (sfVector2f){i * TILE_SIZE - line *
            TILE_SIZE * game->map_size, line * TILE_SIZE}, DIRT_IMG);
    }
}

void destroy_map(tile_t *tile)
{
    while (tile != NULL) {
        sfTexture_destroy(tile->texture);
        sfSprite_destroy(tile->sprite);
        tile = tile->next;
    }
}