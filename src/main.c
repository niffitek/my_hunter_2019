/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** main
*/

#include "../include/game.h"

void spawn_new(objects *object)
{
    if (object->gametime.microseconds / 1000000.0 - object->tmptime > 20 &&
        object->n < 20) {
        object->n += 1;
        object->tmptime += 20;
    }
}

void end(objects *object)
{
    for (int i = 0; i < 20; i += 1) {
        sfSprite_destroy(object->targets[i]->sprite);
        free(object->targets[i]);
    }
    for (int i = 0; i < 5; i += 1)
        free(object->texts[i]);
    free(object->score_texts);
    free(object->lives_texts);
    sfRenderWindow_destroy(object->window);
    sfMusic_destroy(object->song);
    sfClock_destroy(object->clock);
    free(object);
}

int game_over(objects *object)
{
    sfRenderWindow_setMouseCursorVisible(object->window, sfTrue);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event))
            if (game_over_button(object))
                return (1);
        sfRenderWindow_clear(object->window, sfBlack);
        set_text(object->window, object->texts[0], score_handling(object));
        set_text(object->window, object->texts[2], " GAME OVER");
        set_text(object->window, object->texts[3], "Restart");
        set_text(object->window, object->texts[4], "  Exit");
        sfRenderWindow_display(object->window);
    }
    return (1);
}

int start_game(objects *object)
{
    sfRenderWindow_setMouseCursorVisible(object->window, sfFalse);
    while (sfRenderWindow_isOpen(object->window)) {
        if (!object->lives)
            if (game_over(object))
                return (0);
        while (sfRenderWindow_pollEvent(object->window, &object->event))
            event_manager(object);
        object->gametime = sfClock_getElapsedTime(object->clock);
        sfRenderWindow_clear(object->window, sfBlack);
        sfRenderWindow_drawSprite(object->window, object->background, NULL);
        for (int i = 0; i < object->n; i += 1)
            duck_controller(object->targets[i], object);
        set_text(object->window, object->texts[0], score_handling(object));
        set_text(object->window, object->texts[1], live_handling(object));
        set_crosshair(object);
        sfRenderWindow_display(object->window);
        spawn_new(object);
    }
    return (0);
}

int main(int ac, char **av)
{
    objects *object = build_game();
    time_t t;
    srand(time(&t));

    object->song = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setLoop(object->song, 1);
    sfMusic_play(object->song);
    while (sfRenderWindow_isOpen(object->window) && !display_help(ac, av)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event))
            if (menu_button(object)) {
                end(object);
                return (0);
            }
        set_text(object->window, object->texts[2], "PIRATE HUNT");
        set_text(object->window, object->texts[3], "Play");
        set_text(object->window, object->texts[4], "Exit");
        sfRenderWindow_display(object->window);
    }
    end(object);
    return (0);
}
