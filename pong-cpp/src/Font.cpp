#include "Font.hpp"
#include <string.h>
#include <Game.hpp>

extern Game* game;

Font::Font(const char* font_path, const char* text, int font_size, SDL_Color color) : surface(0), texture(0)
{
    this->font_path = strdup(font_path);

    if (TTF_Init() != 0)
    {
        printf("Could not initialize ttf (%s).\n", TTF_GetError());
    }
    this->font = TTF_OpenFont(font_path, 24);

    if (font == NULL)
    {
        printf("Could not open font %s \n", font_path);
        exit(1);
    }

    this->set_text(text, color);
}

void Font::set_text(const char* text, SDL_Color color)
{
    SDL_Renderer* renderer = game->get_renderer();

    if (this->surface != 0)
    {
        SDL_FreeSurface(this->surface);
        this->surface = 0;
    }

    if (this->texture != 0)
    {
        SDL_DestroyTexture(this->texture);
        this->texture = 0;
    }

    this->surface = TTF_RenderText_Solid(this->font, text, color);
    
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Font::draw(float x, float y)
{
    SDL_Renderer* renderer = game->get_renderer();

    int text_width = this->surface->w;
    int text_height = this->surface->h;;

    this->rect = {};
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = text_width;
    this->rect.h = text_height;

    SDL_RenderCopy(renderer, this->texture, NULL, &this->rect);
}