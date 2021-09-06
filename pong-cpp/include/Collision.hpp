#ifndef PONG_COLLISION_H
#define PONG_COLLISION_H
#include <GameObject.hpp>
#include <Game.hpp>

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

typedef struct {
  GameObject* obj;
  Vec2d point;
} CollisionPoint;

bool is_rectangle_colliding(Rectangle rect, Vec2d vec);

bool rect_intersect(Rectangle rect1, Rectangle rect2);

bool get_collision_point(Game* game, GameObject* us, float xa, float ya, CollisionPoint* point);
#endif
