/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#ifndef ASSET_H
#define ASSET_H

#define GET_MUSIC(engine) engine->asset->music

#define GET_JUMP(engine) engine->asset->sounds->jump
#define GET_BUF_JUMP(engine) engine->asset->sounds->buf_jump

#define PARA_NBR 4
#define BUTTON_NBR 2
#define GET_TEXTURE(engine, nbr) engine->asset->textures[nbr]

typedef struct {
    sfSound *jump;
    sfSoundBuffer *buf_jump;
} sounds_t;

typedef enum {
    texParStat,
    texPar1,
    texPar2,
    texPar3,
    texPlay,
    texQuit,
    texPlayer,
    texLoose,
    texGround,

    texSize
} textures_list_t;

typedef struct {
    sfTexture *texture;
    sfIntRect rect_texture;
} textures_t;

typedef struct {
    sfMusic *music;
    sounds_t *sounds;
    textures_t *textures[texSize];
} asset_t;

void create_button(void);
void create_text_sprite(void);
void create_sounds(void);
void create_text_para(void);
void create_textures(void);

void create_asset(void);
void destroy_asset(void);

#endif // ASSET_H
