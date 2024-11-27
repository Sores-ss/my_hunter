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
} duck_animation__t;
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
void update_duck_animation(sfSprite *duck_sprite, duck_animation__t *animation,
    float frame_duration, float seconds);
void update_cursor(sfRenderWindow *window, sfSprite *cursor_sprite);
int check_duck_click(sfSprite *duck_sprite, sfVector2i mouse_pos);
sfSprite *create_duck_sprite(void);
#endif
