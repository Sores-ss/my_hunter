/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** animation.c
*/

#include "../my.h"

static void animate_duck(sfSprite *duck_sprite, sfClock *clock)
{
    static float x_pos = 0;
    static float y_pos = 0;
    const float speed = 2.0f;
    sfTime delta_time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(delta_time);

    if (seconds > 0.01f) {
        x_pos += speed;
        if (x_pos > 2020)
            x_pos = -100;
        sfSprite_setPosition(duck_sprite, (sfVector2f){x_pos, y_pos});
        sfClock_restart(clock);
    }
}

void animate_and_draw(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite, sfClock *clock)
{
    animate_duck(duck_sprite, clock);
    draw_sprites(window, background, duck_sprite);
}
