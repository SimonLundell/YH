#include <Ball.hpp>
#include <Draw.hpp>
#include <Game.hpp>
#include <cmath>
#include <stdio.h>
#include <Math.hpp>
#include <Pad.hpp>
#include <Collision.hpp>
#include <sys/param.h>

extern Game *game;

Ball::Ball(float x, float y) : GameObject(x, y) {
  this->red = 255;
  this->green = 255;
  this->blue = 255;
  this->width = 32;
  this->height = 32;
  int v = random_range(0,4);
  if (v == 0) this-> direction=140;
  else if (v == 1) this-> direction=230;
  else if (v == 2) this-> direction=50;
  else if (v == 3) this-> direction=320;
  this->dx = 0;
  this->dy = 0;
  this->speed = 12.0f;
  this->push(this->direction, speed);
}


void Ball::move(float xa, float ya, float speed) {
  if (xa != 0 && ya != 0) {
    move(xa, 0, speed);
    move(0, ya, speed);
    return;
  }

  float w = this->width;
  float h = this->height;
  float game_w = game->get_width();
  float game_h = game->get_height();

  float next_x = this->x + xa;
  float next_y = this->y + ya;


  // Right wall
  if (next_x + (w) > game_w) {
    this->dx = 0;
    this->push(-180, speed);
    game->reset(WIN_ENEMY);
    return;
  }

  // Left wall
  if (next_x < 0) {
    this->dx = 0;
    this->push(0, speed/2);
    game->reset(WIN_PLAYER);
    return;
  }

  if (next_y + (h) > game_h) {
    this->dy = 0;
    this->push(270, speed/2);
    return;
  }

  if (next_y < 0) {
    this->dy = 0;
    this->push(90, speed/2);
    return;
  }


  std::vector<GameObject*> objects = game->get_game_objects();
  std::vector<GameObject*>::iterator it;


  CollisionPoint point;

  if (get_collision_point(game, this, xa, ya, &point)) {
    Vec2d v = point.point;
    GameObject* obj = point.obj;
    float cx = this->x + this->width/2;
    float cy = this->y + this->height / 2;
    float cx2 = obj->get_x() + obj->get_width() / 2;
    float cy2 = obj->get_y() + obj->get_height() / 2;

    bool left = cx < game->get_height()/2;
    bool right = cx > game->get_width()/2;

    this->dx = 0;
    this->dy = 0;

    float angle = 0;

    // Player
    if (cx <= cx2) 
    {
      if (cy > cy2) 
      {
        angle = 140;
      }
      if (cy < cy2)
      {
        angle = 230;
      }
    }

    // Enemy
    if (cx >= cx2) 
    {
      if (cy > cy2)
      {
        angle = 50;
      }
      if (cy < cy2)
      {
        angle = 320;
      }
    }
    // float angle = atan2(cy - cy2, cx - cx2) * 180 / M_PI;

    if (right)
      this->x += v.x - get_width();
    else
      this->x += v.x;

    this->push(angle, speed);

    return;
  }

  this->x += xa;
  this->y += ya;
}

void Ball::update() {
  float friction = 0.00001f;

  if (this->dx > 0 ) 
  {
      this->dx = MAX(0, this->dx - friction);
  }

  if (this->dx < 0 ) 
  {
      this->dx = MIN(0, this->dx + friction);
  }

  if (this->dy > 0 ) 
  {
      this->dy = MAX(0, this->dy - friction);
  }

  if (this->dy < 0 ) 
  {
      this->dy = MIN(0, this->dy + friction);
  }
  move(this->dx, this->dy, speed);
}

void Ball::draw() {
  draw_circle(this->x, this->y,
              this->width, this->red, this->green, this->blue);
}