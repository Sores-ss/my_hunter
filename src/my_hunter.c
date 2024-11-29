/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** my_hunter.c
*/

#include "../my.h"
#include <SFML/Graphics.h>

int launchmusic(resources_t *resources)
{
    resources->music = sfMusic_createFromFile("audio/opening.ogg");
    if (!resources->music)
        return EXIT_FAILURE;
    return 0;
}

static int create_window(resources_t *resources)
{
    sfVector2u size;
    sfVideoMode mode;

    size = sfTexture_getSize(resources->texture);
    mode = (sfVideoMode){size.x, size.y, 32};
    resources->window = sfRenderWindow_create(mode,
        "Stardew Duck & Hunt", sfClose, NULL);
    if (!resources->window)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(resources->window, 244);
    return EXIT_SUCCESS;
}

static int create_background(resources_t *resources)
{
    resources->background = sfSprite_create();
    if (!resources->background)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int create_cursor_sprite(resources_t *resources)
{
    sfTexture *cursor_texture = sfTexture_createFromFile("sprites/cursor.png",
        NULL);
    sfVector2u cursor_size = sfTexture_getSize(cursor_texture);

    if (!cursor_texture)
        return EXIT_FAILURE;
    resources->cursor_sprite = sfSprite_create();
    sfSprite_setTexture(resources->cursor_sprite, cursor_texture, sfTrue);
    sfSprite_setOrigin(resources->cursor_sprite, (sfVector2f){cursor_size.x
        / 2, cursor_size.y / 2});
    sfRenderWindow_setMouseCursorVisible(resources->window, sfFalse);
    return EXIT_SUCCESS;
}

static int initialize_resources(resources_t *resources)
{
    resources->texture = sfTexture_createFromFile("sprites/nightlayout.jpg",
        NULL);
    if (!resources->texture)
        return EXIT_FAILURE;
    if (launchmusic(resources) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (create_window(resources) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (create_background(resources) == EXIT_FAILURE) {
        sfRenderWindow_destroy(resources->window);
        return EXIT_FAILURE;
    }
    if (create_cursor_sprite(resources) == EXIT_FAILURE) {
        cleanup_resources(resources);
        return EXIT_FAILURE;
    }
    sfMusic_play(resources->music);
    sfMusic_setLoop(resources->music, sfTrue);
    return EXIT_SUCCESS;
}

void cleanup_resources(resources_t *resources)
{
    if (resources->cursor_sprite)
        sfSprite_destroy(resources->cursor_sprite);
    if (resources->texture)
        sfTexture_destroy(resources->texture);
    if (resources->background)
        sfSprite_destroy(resources->background);
    if (resources->window)
        sfRenderWindow_destroy(resources->window);
    if (resources->music)
        sfMusic_destroy(resources->music);
}

int start_game(void)
{
    resources_t resources;

    if (initialize_resources(&resources) == EXIT_FAILURE) {
        cleanup_resources(&resources);
        return EXIT_FAILURE;
    }
    display_all(&resources);
    cleanup_resources(&resources);
    return EXIT_SUCCESS;
}
