/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdlib.h>
typedef struct duck_animation_s {
    int current_frame;
    float animation_time;
} duck_animation_t;
typedef struct duck_s {
    sfSprite *sprite;
    sfVector2f position;
    float speed;
    duck_animation_t animation;
} duck_t;
typedef struct cursor_s {
    sfSprite *sprite;
    sfVector2f position;
} cursor_t;
typedef struct game_window_s {
    sfRenderWindow *window;
    sfSprite *background;
    sfTexture *background_texture;
} game_window_t;
typedef struct score_s {
    int current_score;
    int high_score;
} score_t;

int start_game(void);
void display_background(sfTexture *texture, sfRenderWindow *window,
    sfSprite *sprite);
void handle_events(sfRenderWindow *window, sfEvent event);
void sfclose(sfEvent event, sfRenderWindow *window);
void draw_sprites(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite);
void animate_and_draw(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite, sfClock *clock);
void update_duck_position(sfSprite *duck_sprite, float *x_pos,
    float *y_pos, float speed);
void update_duck_animation(sfSprite *duck_sprite, duck_animation_t *animation,
    float frame_duration, float seconds);
void update_cursor(sfRenderWindow *window, sfSprite *cursor_sprite);
int check_duck_click(sfSprite *duck_sprite, sfVector2i mouse_pos);
sfSprite *create_duck_sprite(void);
#endif
