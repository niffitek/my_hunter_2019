/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** text_handling
*/

#include "../include/game.h"

ui_text *create_text(int x, int y, int size)
{
    ui_text *score = malloc(sizeof(ui_text));
    score->text = sfText_create();
    score->font = sfFont_createFromFile("assets/font.ttf");
    score->pos.x = x;
    score->pos.y = y;

    sfText_setFont(score->text, score->font);
    sfText_setCharacterSize(score->text, size);
    sfText_setPosition(score->text, score->pos);
    return (score);
}

void set_text(sfRenderWindow *window, ui_text *text, char *str)
{
    sfText_setString(text->text, str);
    sfRenderWindow_drawText(window, text->text, NULL);
}

char *score_handling(objects *object)
{
    if (object->score < 0)
        object->score = 0;
    object->score_texts[0] = 'S';
    object->score_texts[1] = 'c';
    object->score_texts[2] = 'o';
    object->score_texts[3] = 'r';
    object->score_texts[4] = 'e';
    object->score_texts[5] = ':';
    object->score_texts[6] = ' ';
    object->score_texts[7] = object->score / 100 + 48;
    object->score_texts[8] = object->score / 10 % 10 + 48;
    object->score_texts[9] = object->score % 10 + 48;
    object->score_texts[10] = '\0';
    return (object->score_texts);
}

char *live_handling(objects *object)
{
    object->lives_texts[0] = 'L';
    object->lives_texts[1] = 'i';
    object->lives_texts[2] = 'v';
    object->lives_texts[3] = 'e';
    object->lives_texts[4] = 's';
    object->lives_texts[5] = ':';
    object->lives_texts[6] = ' ';
    object->lives_texts[7] = object->lives + 48;
    object->lives_texts[8] = '\0';
    return (object->lives_texts);
}