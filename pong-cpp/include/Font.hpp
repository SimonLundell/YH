#ifndef PONG_FONT_H
#define PONG_FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
    public:
        Font(const char* font_path, const char* text, int font_size, SDL_Color color);
        void draw(float x, float y);
        void set_text(const char* text, SDL_Color color);
    private:
        SDL_Rect rect;
        SDL_Texture* texture;
        SDL_Surface* surface;
        int font_size;
        char* font_path;
        TTF_Font* font;
};

#endif