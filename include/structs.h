/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef MUL_MY_HUNTER_2019_STRUCTS_H
#define MUL_MY_HUNTER_2019_STRUCTS_H

typedef struct duck_s
{
    sfVector2f move;
    sfVector2f spawn;
    sfVector2f scale;
    sfSprite *sprite;
    sfIntRect anim;
    double tmptime;
    int score;
    int type;
} duck;

typedef struct text_s
{
    sfFont *font;
    sfVector2f pos;
    sfText *text;
} ui_text;

typedef struct objects_s
{
    sfRenderWindow *window;
    sfSprite *background;
    sfSprite *mouse;
    sfEvent event;
    duck *targets[20];
    sfClock *clock;
    sfTime gametime;
    sfMusic *song;
    ui_text *texts[5];
    int n;
    int tmptime;
    int score;
    char *score_texts;
    int lives;
    char *lives_texts;
} objects;

#endif //MUL_MY_HUNTER_2019_STRUCTS_H
