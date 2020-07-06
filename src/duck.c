/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

duck *instantiate_duck(sfRenderWindow *window)
{
    duck *new = malloc(sizeof(duck));
    new->sprite = sfSprite_create();
    new->anim.left = 0;
    new->anim.top = 0;
    new->anim.width = 30;
    new->anim.height = 30;
    new->scale.y = new->scale.x;
    new->tmptime = 0;
    new->move.y = 0;
    new->score = 0;

    sfSprite_setTextureRect(new->sprite, new->anim);
    reinstantiate_duck(new);
    return (new);
}

duck *set_texture(duck *new)
{
    sfTexture *ship2 = sfTexture_createFromFile("assets/ship2.png", NULL);
    sfTexture *ship3 = sfTexture_createFromFile("assets/ship3.png", NULL);
    if (new->type < 5 && new->move.x > 0) {
        new->move.x = 10;
        sfSprite_setTexture(new->sprite, ship2, sfFalse);
    }
    else if (new->type < 5 && new->move.x < 0) {
        new->move.x = -10;
        sfSprite_setTexture(new->sprite, ship2, sfFalse);
    }
    else {
        if (new->type > 5 && new->type < 10 && new->move.x > 0) {
            new->move.x = 7;
            sfSprite_setTexture(new->sprite, ship3, sfFalse);
        }
        else if (new->type > 5 && new->type < 10 && new->move.x < 0) {
            new->move.x = -7;
            sfSprite_setTexture(new->sprite, ship3, sfFalse);
        }
    }
    return (new);
}

void reinstantiate_duck(duck *new)
{
    new->spawn.y = rand() % (900 + 1 - 200) + 200;
    new->move.x = rand() % 10 - 5;
    new->scale.x = rand() % (5 + 1 - 2) + 2;
    new->type = rand() % 25;
    new->scale.y = new->scale.x;
    sfTexture *ship1 = sfTexture_createFromFile("assets/ship1.png", NULL);

    if (new->move.x == 0)
        new->move.x = 1;
    if (new->move.x >= 0)
        new->spawn.x = -100;
    else {
        new->spawn.x = 2000;
        new->scale.x = -new->scale.x;
    }
    sfSprite_setPosition(new->sprite, new->spawn);
    sfSprite_setScale(new->sprite, new->scale);
    sfSprite_setTexture(new->sprite, ship1, sfFalse);
    new = set_texture(new);
}

void animate_duck(duck *target)
{
    if (target->anim.left < 60)
        target->anim.left += 30;
    else
        target->anim.left = 0;
    sfSprite_setTextureRect(target->sprite, target->anim);
}

void duck_controller(duck *target, objects *object)
{
    sfVector2f pos;
    double seconds;

    seconds = object->gametime.microseconds / 1000000.0;
    pos = sfSprite_getPosition(target->sprite);
    if (pos.x >= -100 && pos.x < 2020) {
        if (seconds - target->tmptime > 0.25) {
            animate_duck(target);
            target->tmptime = seconds;
        }
        sfRenderWindow_drawSprite(object->window, target->sprite, NULL);
        sfSprite_move(target->sprite, target->move);
    }
    else {
        if (target->type <= 5 || target->type >= 10)
            object->lives -= 1;
        reinstantiate_duck(target);
    }
}