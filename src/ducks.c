/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** ducks.c
*/

#include "../my.h"

void draw_ducks(sfRenderWindow *window, duck_t *ducks)
{
    for (int i = 0; i < MAX_DUCKS; i++) {
        if (ducks[i].is_active) {
            sfRenderWindow_drawSprite(window, ducks[i].sprite, NULL);
        }
    }
}

void initialize_and_spawn_ducks(duck_t *ducks)
{
    srand(time(NULL));
    for (int i = 0; i < MAX_DUCKS; i++) {
        ducks[i].sprite = create_duck_sprite();
        reset_duck(&ducks[i]);
    }
    spawn_new_duck(ducks);
}

void spawn_new_duck(duck_t *ducks)
{
    for (int i = 0; i < MAX_DUCKS; i++) {
        if (!ducks[i].is_active) {
            reset_duck(&ducks[i]);
            break;
        }
    }
}

void update_ducks_position(duck_t *ducks, float delta_time)
{
    for (int i = 0; i < MAX_DUCKS; i++) {
        if (ducks[i].is_active) {
            ducks[i].position.x += ducks[i].speed_x;
            ducks[i].position.y += ducks[i].speed_y;
            update_ducks_pos2(ducks, i);
            sfSprite_setPosition(ducks[i].sprite, ducks[i].position);
            animate_duck(&ducks[i], delta_time);
        }
    }
    spawn_new_duck(ducks);
}

void update_ducks_pos2(duck_t *ducks, int i)
{
    if (ducks[i].position.y < 0 || ducks[i].position.y > 600) {
        ducks[i].speed_y *= -1;
    }
    if (ducks[i].position.x > 2000) {
        ducks[i].is_active = 0;
    }
}
