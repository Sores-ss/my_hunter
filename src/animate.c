/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** animate.c
*/

#include "../my.h"

void animate_duck(duck_t *duck, float delta_time)
{
    const int total_frames = 3;
    const int frame_width = FRAME_WIDTH;
    const int frame_height = FRAME_HEIGHT;
    sfIntRect rect = {duck->animation_frame * frame_width,
        0, frame_width, frame_height};

    duck->animation_time += delta_time;
    if (duck->animation_time >= FRAME_DURATION) {
        duck->animation_time = 0.0f;
        duck->animation_frame = (duck->animation_frame + 1) % total_frames;
        sfSprite_setTextureRect(duck->sprite, rect);
    }
}
