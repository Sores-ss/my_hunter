/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** display.c
*/

#include "../my.h"

void draw_sprites(sfRenderWindow *window, sfSprite *background,
    duck_t *ducks)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background, NULL);
    draw_ducks(window, ducks);
    sfRenderWindow_display(window);
}

void reset_duck(duck_t *duck)
{
    duck->position = (sfVector2f){-100, rand() % 600};
    duck->speed_x = 0.1f + (rand() % 2 * 0.05f);
    duck->speed_y = (rand() % 2 - 1.0f) * 0.1f;
    duck->animation_frame = 0;
    duck->animation_time = 0.0f;
    duck->is_active = 1;
}

void display_loop(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
}

void display_all(sfTexture *texture, sfRenderWindow *window,
    sfSprite *background, sfEvent event)
{
    sfClock *clock = sfClock_create();
    duck_t ducks[MAX_DUCKS];
    float delta_time = 0.0f;

    initialize_and_spawn_ducks(ducks);
    sfSprite_setTexture(background, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        display_loop(window, event);
        delta_time = sfClock_restart(clock).microseconds / 1000000.0f;
        update_ducks_position(ducks, delta_time);
        draw_sprites(window, background, ducks);
    }
    sfClock_destroy(clock);
}
