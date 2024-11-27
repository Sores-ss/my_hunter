/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** display.c
*/

#include "../my.h"

void draw_sprites(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawSprite(window, duck_sprite, NULL);
    sfRenderWindow_display(window);
}

void display_background(sfTexture *texture, sfRenderWindow *window,
    sfSprite *background)
{
    sfVector2f duck_pos = {0, 0};
    sfSprite *duck_sprite = create_duck_sprite();
    sfEvent event;
    sfClock *clock = sfClock_create();

    sfSprite_setTexture(background, texture, sfTrue);
    sfSprite_setPosition(duck_sprite, duck_pos);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            handle_events(window, event);
        animate_and_draw(window, background, duck_sprite, clock);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(duck_sprite);
    sfClock_destroy(clock);
}
