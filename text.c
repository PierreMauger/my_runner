/*
** EPITECH PROJECT, 2020
** Base
** File description:
** text
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

void init_text(text_t **temp)
{
    text_t *text = *temp;

    text->str = malloc(10);
    text->font = sfFont_createFromFile("ressources/font");
    text->score = 0;
    text->score_text = set_text(text->score_text, text, sfBlack);
    sfText_setPosition(text->score_text, (sfVector2f){100, 100});
}

sfText *set_text(sfText *str, text_t *text, sfColor color)
{
    str = sfText_create();
    sfText_setString(str, text->str);
    sfText_setFont(str, text->font);
    sfText_setCharacterSize(str, 50);
    sfText_setColor(str, color);
    return str;
}

void draw_text(game_t *game)
{
    char s[9] = "Score : ";

    game->text->str = my_strcat(s, my_put_nbr(game->text->score));
    sfText_setString(game->text->score_text, game->text->str);
    sfRenderWindow_drawText(game->window, game->text->score_text, NULL);
}
