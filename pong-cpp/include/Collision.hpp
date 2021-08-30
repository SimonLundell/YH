#ifndef PONG_COLLISION_H
#define PONG_COLLISION_H

struct Vec2d {
  float x;
  float y;
};

struct Rectangle {
  float x;
  float y;
  float width;
  float height;
};

bool is_rectangle_colliding(Rectangle rect, Vec2d vec);

#endif
