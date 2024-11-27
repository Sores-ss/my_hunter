/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** animation.c
*/

#include "../my.h"

sfSprite *create_duck_sprite(void)
{
    sfTexture *duck_texture = sfTexture_createFromFile("sprites/duck.png",
        NULL);
    sfSprite *duck_sprite = sfSprite_create();

    if (!duck_texture)
        return NULL;
    sfSprite_setTexture(duck_sprite, duck_texture, sfTrue);
    return duck_sprite;
}

void update_duck_position(sfSprite *duck_sprite, float *x_pos,
    float *y_pos, float speed)
{
    *x_pos += speed;
    if (*x_pos > 2020) {
        *x_pos = -100;
    }
    sfSprite_setPosition(duck_sprite, (sfVector2f){*x_pos, *y_pos});
}

void update_duck_animation(sfSprite *duck_sprite,
    duck_animation_t *animation, float frame_duration, float seconds)
{
    const int frame_width = 110;
    const int frame_height = 110;
    const int total_frames = 3;
    sfIntRect rect = {
        animation->current_frame * frame_width, 0, frame_width,
            frame_height
        };

    animation->animation_time += seconds;
    if (animation->animation_time >= frame_duration) {
        animation->current_frame = (animation->current_frame + 1)
            % total_frames;
        sfSprite_setTextureRect(duck_sprite, rect);
        animation->animation_time = 0.0f;
    }
}

void animate_duck(sfSprite *duck_sprite, sfClock *clock)
{
    static float x_pos = -400;
    static float y_pos = 0;
    static duck_animation_t animation = {0, 0.0f};
    const float speed = 2.0f;
    const float frame_duration = 0.2f;
    sfTime delta_time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(delta_time);

    if (seconds > 0.01f) {
        update_duck_position(duck_sprite, &x_pos, &y_pos, speed);
        update_duck_animation(duck_sprite, &animation,
            frame_duration, seconds);
        sfClock_restart(clock);
    }
}

void animate_and_draw(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite, sfClock *clock)
{
    animate_duck(duck_sprite, clock);
    draw_sprites(window, background, duck_sprite);
}
