#ifndef DRAW_H
#define DRAW_H

void draw_pixel(
  int x,
  int y,
  unsigned int red,
  unsigned int green,
  unsigned int blue
);


void draw_circle(
  int x,
  int y,
  int dia,
  unsigned int red,
  unsigned int green,
  unsigned int blue
);

void draw_rect(
    int x,
    int y,
    int width,
    int height,
    unsigned int red,
    unsigned int green,
    unsigned int blue
);

#endif
