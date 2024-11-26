/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** my.h
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdlib.h>
void display_background(sfTexture *texture, sfRenderWindow *window,
    sfSprite *sprite);
void handle_events(sfRenderWindow *window, sfEvent event);
void sfclose(sfEvent event, sfRenderWindow *window);
void draw_sprites(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite);
void animate_and_draw(sfRenderWindow *window, sfSprite *background,
    sfSprite *duck_sprite, sfClock *clock);
#endif
