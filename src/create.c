/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/game.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode, "my_hunter", sfDefaultStyle,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

sfSprite *create_background(void)
{
    sfTexture *bg = sfTexture_createFromFile("assets/background.png", NULL);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, bg, sfFalse);
    return (background);
}

int display_help(int ac, char **av)
{
    char buffer[500];
    int fd = open("help", O_RDONLY);
    int size = read(fd, buffer, 500);

    buffer[size] = '\0';
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h') {
            write(1, buffer, size);
            return (1);
        }
    return (0);
}

objects *build_texts(objects *object)
{
    object->score_texts = malloc(sizeof(char) * 11);
    object->lives_texts = malloc(sizeof(char) * 9);
    object->texts[0] = create_text(10, 0, 70);
    object->texts[1] = create_text(10, 40, 70);
    object->texts[2] = create_text(250, 50, 300);
    object->texts[3] = create_text(850, 600, 80);
    object->texts[4] = create_text(850, 700, 80);
    return (object);
}

objects *build_game(void)
{
    objects *object = malloc(sizeof(objects));
    object->window = create_window();
    object->background = create_background();
    object->mouse = create_crosshair();
    for (int i = 0; i < 20; i += 1)
        object->targets[i] = instantiate_duck(object->window);
    object->clock = sfClock_create();
    object->n = 1;
    object->tmptime = 0;
    object->score = 0;
    object->lives = 3;
    object = build_texts(object);
    return (object);
}