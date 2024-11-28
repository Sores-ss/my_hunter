/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-eros.delianne-le-boucher
** File description:
** sprites.c
*/

#include "../my.h"

sfSprite *create_duck_sprite(void)
{
    sfTexture *duck_texture = sfTexture_createFromFile
        ("sprites/duck.png", NULL);
    sfSprite *duck_sprite = sfSprite_create();

    sfSprite_setTexture(duck_sprite, duck_texture, sfTrue);
    return duck_sprite;
}
