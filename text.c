/*
** EPITECH PROJECT, 2020
** Base
** File description:
** text
*/

#include "my_runner.h"
#include <string.h>

static char *concat(const char *s1, const char *s2)
{
    char *result = malloc(my_strlen(s1) + my_strlen(s2) + 1);

    my_strcpy(result, s1);
    my_strcat(result, s2);
    return result;
}

void init_text(game_t *game)
{
    game->text = malloc(sizeof(text_t));
    game->text->str = "Score : ";
    game->text->font = sfFont_createFromFile("ressources/font");
    game->text->score_text = sfText_create();
    sfText_setFont(game->text->score_text, game->text->font);
    sfText_setCharacterSize(game->text->score_text, 50);
    sfText_setColor(game->text->score_text, sfBlack);
    game->text->score = 0;
    sfText_setPosition(game->text->score_text, (sfVector2f){100, 100});
}

void draw_text(game_t *game)
{
    game->text->str = concat("Score : ", my_put_nbr(game->text->score));
    sfText_setString(game->text->score_text, game->text->str);
    sfRenderWindow_drawText(game->window, game->text->score_text, NULL);
}
