/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** m handling
*/

#include "../include/game.h"

void hit(objects *object, int i)
{
    if (object->targets[i]->type < 5)
        object->score += 5;
    else if (object->targets[i]->type > 5 && object->targets[i]->type < 10)
        object->score -= 10;
    else
        object->score += 1;
    reinstantiate_duck(object->targets[i]);
}

sfSprite *create_crosshair(void)
{
    sfTexture *crosshair = sfTexture_createFromFile("assets/crosshair.png",
        NULL);
    sfVector2f scale;
    scale.x = 0.2f;
    scale.y = 0.2f;
    sfSprite *mouse = sfSprite_create();
    sfSprite_setTexture(mouse, crosshair, sfFalse);
    sfSprite_setScale(mouse, scale);
    return (mouse);
}

void set_crosshair(objects *object)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(object->window);
    sfVector2f pos;
    pos.x = m_pos.x - 26;
    pos.y = m_pos.y - 26;
    sfSprite_setPosition(object->mouse, pos);
    sfRenderWindow_drawSprite(object->window, object->mouse, NULL);
}

void shoot(objects *object)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(object->window);
    sfVector2f d_pos;

    for (int i = 0; i < 20; i += 1) {
        d_pos = sfSprite_getPosition(object->targets[i]->sprite);
        if (object->targets[i]->move.x > 0 && (m_pos.x >= d_pos.x &&
        m_pos.x <= d_pos.x + 40 * object->targets[i]->scale.y)) {
            if (m_pos.y >= d_pos.y && m_pos.y <= d_pos.y + 30 *
            object->targets[i]->scale.y) {
                hit(object, i);
                break;
            }
        } else if (object->targets[i]->move.x < 0 && (m_pos.x <= d_pos.x &&
        m_pos.x >= d_pos.x - 40 * object->targets[i]->scale.y)) {
            if (m_pos.y >= d_pos.y && m_pos.y <= d_pos.y + 30 *
            object->targets[i]->scale.y) {
                hit(object, i);
                break;
            }
        }
    }
}