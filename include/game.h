/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** functions
*/

#ifndef MUL_MY_HUNTER_2019_GAME_H
#define MUL_MY_HUNTER_2019_GAME_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include "../include/structs.h"

int start_game(objects *object);
int game_over(objects *object);
void end(objects *object);

int         event_manager(objects *object);
int         menu_button(objects *object);
int         game_over_button(objects *object);

sfSprite    *create_crosshair(void);
void        set_crosshair(objects *object);
void shoot(objects *object);

duck *instantiate_duck(sfRenderWindow *window);
void reinstantiate_duck(duck *new);
void animate_duck(duck *target);
void duck_controller(duck *target, objects *object);

ui_text *create_text(int x, int y, int size);
void set_text(sfRenderWindow *window, ui_text *text, char *str);
char *score_handling(objects *object);
char *live_handling(objects *object);

objects *build_game(void);
sfSprite *create_background(void);
sfRenderWindow *create_window(void);
int display_help(int ac, char **av);

#endif //MUL_MY_HUNTER_2019_GAME_H
