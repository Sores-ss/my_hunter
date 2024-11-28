/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <time.h>

    #define MAX_DUCKS 5
    #define FRAME_DURATION 0.1f
    #define TOTAL_FRAMES 3
    #define FRAME_WIDTH 111
    #define FRAME_HEIGHT 111

typedef struct duck_s {
    sfSprite *sprite;
    sfVector2f position;
    float speed_x;
    float speed_y;
    int animation_frame;
    float animation_time;
    int is_active;
} duck_t;

void draw_sprites(sfRenderWindow *window, sfSprite *background, duck_t *ducks);
void reset_duck(duck_t *duck);
void display_all(sfTexture *texture, sfRenderWindow *window,
    sfSprite *background, sfEvent event);
void initialize_and_spawn_ducks(duck_t *ducks);
void spawn_new_duck(duck_t *ducks);
void update_ducks_position(duck_t *ducks, float delta_time);
void draw_ducks(sfRenderWindow *window, duck_t *ducks);
sfSprite *create_duck_sprite(void);
void animate_duck(duck_t *duck, float delta_time);
void update_ducks_pos2(duck_t *ducks, int i);

int start_game(void);

#endif
