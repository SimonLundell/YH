#include "Pad.hpp"
#include "Draw.hpp"

Pad::Pad(float x, float y) : GameObject(x, y)
{
    this->width = 32;
    this->height = 86;

    this->red = 255;
    this->green = 255;
    this->blue = 255;
}

void Pad::draw_default() {
  draw_rect(this->x, this->y,
            this->width, this->height, this->red, this->green, this->blue);
}