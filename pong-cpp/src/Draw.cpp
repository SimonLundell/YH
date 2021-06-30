#include <Draw.hpp>
#include <Game.hpp>
#include <Math.hpp>
#include <cmath>

extern Game* game;

// raise your hand once you don't have any errors here

void draw_pixel(
  int x,
  int y,
  unsigned int red,
  unsigned int green,
  unsigned int blue
) {
  SDL_Renderer* renderer = game->get_renderer();

  SDL_SetRenderDrawColor(
    renderer,
    red,
    green,
    blue,
    1    // alpha
  );

  SDL_RenderDrawPoint(renderer, x, y);

  SDL_SetRenderDrawColor(
    renderer,
    0,
    0,
    0,
    1    // alpha
  );
}

// raise your hand once you have this function in Draw.cpp
void draw_circle(
  int x,
  int y,
  int dia,
  unsigned int red,
  unsigned int green,
  unsigned int blue
) {
  float centerx = x + (dia / 2);
  float centery = y + (dia / 2);

  for (int i = 0; i < 360; i++) {
    draw_pixel(
      centerx + std::cos(to_radians(i)) * (dia / 2),
      centery + std::sin(to_radians(i)) * (dia / 2),
      red,
      green,
      blue
    );
  }
}

void draw_rect(
    int x,
    int y,
    int width,
    int height,
    unsigned int red,
    unsigned int green,
    unsigned int blue
) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_Renderer* renderer = game->get_renderer();

    SDL_SetRenderDrawColor(
        renderer,
        red,
        green,
        blue,
        1    // alpha
    );

    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        1    // alpha
    );
}