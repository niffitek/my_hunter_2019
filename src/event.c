/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

int event_manager(objects *object)
{
    if (object->event.type == sfEvtClosed)
        sfRenderWindow_close(object->window);
    if (object->event.type == sfEvtMouseButtonPressed) {
        if (object->event.mouseButton.button == sfMouseLeft)
            shoot(object);
    }
    return (0);
}

int restart_game(objects *object)
{
    object = build_game();
    if (!start_game(object))
        return (1);
    return (0);
}

int check_button(objects *object)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(object->window);

    if ((m_pos.x >= 750 && m_pos.x <= 1100) && (m_pos.y >= 600 &&
    m_pos.y <= 699))
        return (restart_game(object));
    else if ((m_pos.x >= 750 && m_pos.x <= 1100) && (m_pos.y >= 720 &&
    m_pos.y <= 800))
        return (1);
    else
        return (0);
}

int menu_button(objects *object)
{
    if (object->event.type == sfEvtClosed)
        sfRenderWindow_close(object->window);
    if (object->event.type == sfEvtMouseButtonPressed) {
        if (object->event.mouseButton.button == sfMouseLeft)
            return (check_button(object));
    }
    return (0);
}

int game_over_button(objects *object)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(object->window);
    if (object->event.type == sfEvtClosed)
        sfRenderWindow_close(object->window);
    if (object->event.type == sfEvtMouseButtonPressed) {
        if (object->event.mouseButton.button == sfMouseLeft)
            return (check_button(object));
    }
    return (0);
}