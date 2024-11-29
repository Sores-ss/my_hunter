/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** display.c
*/

#include "../my.h"

void draw_sprites(resources_t *resources, duck_t *ducks)
{
    sfVector2i mouse_position =
        sfMouse_getPositionRenderWindow(resources->window);

    sfRenderWindow_clear(resources->window, sfBlack);
    sfRenderWindow_drawSprite(resources->window, resources->background, NULL);
    draw_ducks(resources->window, ducks);
    sfSprite_setPosition(resources->cursor_sprite,
        (sfVector2f){mouse_position.x, mouse_position.y});
    sfRenderWindow_drawSprite(resources->window,
        resources->cursor_sprite, NULL);
    sfRenderWindow_display(resources->window);
}

void reset_duck(duck_t *duck)
{
    duck->position = (sfVector2f){-100, rand() % 600};
    duck->speed_x = 1.0f + (rand() % 2 * 1.0f);
    duck->speed_y = (rand() % 2 - 1.0f) * 1.0f;
    duck->animation_frame = 0;
    duck->animation_time = 0.0f;
    duck->is_active = 1;
}

void display_all(resources_t *resources)
{
    sfClock *clock = sfClock_create();
    duck_t ducks[MAX_DUCKS];
    float delta_time = 0.0f;
    sfEvent event;

    initialize_and_spawn_ducks(ducks);
    sfSprite_setTexture(resources->background, resources->texture, sfTrue);
    while (sfRenderWindow_isOpen(resources->window)) {
        while (sfRenderWindow_pollEvent(resources->window, &event)) {
            handle_events(resources->window, event, ducks);
        }
        delta_time = sfClock_restart(clock).microseconds / 1000000.0f;
        update_ducks_position(ducks, delta_time);
        draw_sprites(resources, ducks);
    }
    sfClock_destroy(clock);
}
