/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "my_runner.h"

void put_in_enemy_list(enemy_t **enemy, sfVector2f pos, char *asset)
{
    enemy_t *element = malloc(sizeof(enemy_t));

    element->pos = pos;
    element->texture = sfTexture_createFromFile(asset, NULL);
    element->sprite = sfSprite_create();
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
    sfSprite_setPosition(element->sprite, element->pos);
    element->rect = (sfIntRect){0, 0, PLAYER_WIDTH, PLAYER_HEIGHT};
    element->next = *enemy;
    *enemy = element;
}

void spawn_entity(game_t *game)
{
    for (int i = 0; i < game->map_size / 10; i++)
        put_in_enemy_list(&game->enemy, (sfVector2f){rand() % (game->map_size -
        100) * TILE_SIZE + 1000, rand() % 300 + 100}, DIRT_IMG);
}

void draw_enemy(game_t *game)
{
    enemy_t *temp = game->enemy;

    while (temp != NULL) {
        sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        temp = temp->next;
    }
}

void move_enemy(game_t *game)
{
    enemy_t *temp = game->enemy;

    while (temp != NULL) {
        sfSprite_move(temp->sprite, (sfVector2f){-12, 0});
        temp->pos = sfSprite_getPosition(temp->sprite);
        temp = temp->next;
    }
}

void destroy_enemy(enemy_t *enemy)
{
    while (enemy != NULL) {
        sfTexture_destroy(enemy->texture);
        sfSprite_destroy(enemy->sprite);
        enemy = enemy->next;
    }
}