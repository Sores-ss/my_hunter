/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** events.c
*/

#include "../my.h"

void sfclose(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void handle_events(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfclose(event, window);
}
