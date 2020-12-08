/*
** EPITECH PROJECT, 2020
** Base
** File description:
** data
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my_runner.h"

void init_data(data_t **temp)
{
    data_t *data = *temp;

    data->str = malloc(10);
    data->font = sfFont_createFromFile("ressources/font");
    data->score = 0;
    data->score_text = set_text(data->score_text, data, sfBlack);
    sfText_setPosition(data->score_text, (sfVector2f){100, 100});
}

sfText *set_text(sfText *text, data_t *data, sfColor color)
{
    text = sfText_create();
    sfText_setString(text, data->str);
    sfText_setFont(text, data->font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, color);
    return text;
}

void draw_text(game_t *game)
{
    char s[9] = "Score : ";

    game->data->str = my_strcat(s, my_put_nbr(game->data->score));
    sfText_setString(game->data->score_text, game->data->str);
    sfRenderWindow_drawText(game->window, game->data->score_text, NULL);
}
