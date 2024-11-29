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

void event_loop3(duck_t *ducks, sfFloatRect bounds, sfVector2i mouse_position,
    int i)
{
    if (sfFloatRect_contains(&bounds, mouse_position.x, mouse_position.y)) {
                ducks[i].is_active = 0;
                return;
            }
}

void event_loop2(duck_t *ducks, sfRenderWindow *window)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
    int i = 0;
    sfFloatRect bounds;

    for (i = 0; i < MAX_DUCKS; i++) {
        if (ducks[i].is_active) {
            bounds = sfSprite_getGlobalBounds(ducks[i].sprite);
            bounds.width *= 1.25;
            bounds.height *= 1.25;
            bounds.left -= (bounds.width * 0.25);
            bounds.top -= (bounds.height * 0.25);
            event_loop3(ducks, bounds, mouse_position, i);
        }
    }
}

void event_loop(duck_t *ducks, sfRenderWindow *window)
{
    int i = 0;

    for (; i < MAX_DUCKS; i++) {
            if (ducks[i].is_active) {
                event_loop2(ducks, window);
            }
        }
}

void handle_events(sfRenderWindow *window, sfEvent event, duck_t *ducks)
{
    if (event.type == sfEvtClosed)
        sfclose(event, window);
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        event_loop(ducks, window);
    }
}
