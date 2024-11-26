/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** main.c
*/

#include "my.h"

static sfRenderWindow *create_window(sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);
    sfVideoMode mode = (sfVideoMode){size.x, size.y, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Stardew Duck & Hunt"
    , sfClose, NULL);

    return window;
}

static int initialize_resources(sfRenderWindow **window, sfSprite **background
    , sfTexture **texture)
{
    *texture = sfTexture_createFromFile("sprites/nightlayout.jpg", NULL);
    if (!*texture)
        return EXIT_FAILURE;
    *window = create_window(*texture);
    if (!*window)
        return EXIT_FAILURE;
    *background = sfSprite_create();
    if (!*background) {
        sfRenderWindow_destroy(*window);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static void cleanup_resources(sfRenderWindow *window,
    sfSprite *background, sfTexture *texture)
{
    if (texture)
        sfTexture_destroy(texture);
    if (background)
        sfSprite_destroy(background);
    if (window)
        sfRenderWindow_destroy(window);
}

int main(void)
{
    sfRenderWindow *window = NULL;
    sfSprite *background = NULL;
    sfTexture *texture = NULL;

    if (initialize_resources(&window, &background, &texture) == EXIT_FAILURE) {
        cleanup_resources(window, background, texture);
        return EXIT_FAILURE;
    }
    display_background(texture, window, background);
    cleanup_resources(window, background, texture);
    return EXIT_SUCCESS;
}
