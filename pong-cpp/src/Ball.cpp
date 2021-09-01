#include <iostream>
#include <Ball.hpp>
#include <stdio.h>
#include <Game.hpp>
#include <Draw.hpp>
#include <cmath>
#include <Math.hpp>
#include <Pad.hpp>
#include <Collision.hpp>

extern Game* game;

Ball::Ball(float x, float y) : GameObject(x, y) {
  this->red = 255;
  this->green = 255;
  this->blue = 255;
  this->width = 32;
  this->height = 32;
  this->direction = random_range(0,360);
  this->dx = 1;
  this->dy = 1;
}

void Ball::update() 
{
  float speed = 0.1f;
  float rad = to_radians(this->direction);
  
  float next_x = std::cos(rad) * speed * this->dx;
  float next_y = std::sin(rad) * speed * this->dy;

  move(next_x, next_y, speed);
}

void Ball::draw() {
    draw_circle(this->x - (this->width/2), 
    this->y - (this->height/2), 
    this->width, 
    this->red, 
    this->green, 
    this->blue);
  }

void Ball::move(float dx, float dy, float speed)
{
  if (dx != 0 && dy != 0)
  {
    move(dx, 0, speed);
    move(0, dy, speed);
    return;
  }

  float w = this->width;
  float h = this->height;
  float game_w = game->get_width();
  float game_h = game->get_height();

  float next_x = this->x + dx;
  float next_y = this->y + dy;

  if (next_x + (w/2) > game_w)
  {
    this->dx = -1 * this->dx;
    return;
  }
  if (next_x - (w/2) < 0) 
  {
    this->dx = -1 * this->dx;
    return;
  }
  if (next_y + (h/2) > game_h)
  {
    this->dy = -1 * this->dy;
    return;
  }
  if (next_y - (h/2) < 0) 
  {
    this->dy = -1 * this->dy;
    return;
  }
  
  std::vector<GameObject*> objects = game->get_game_objects();

  for (std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++)
  {
    GameObject* obj = *it;
    
    if (dynamic_cast<Pad*>(obj) == nullptr)
      continue;

    // Pad rect    
    Rectangle rect1;
    rect1.x = obj->get_x() - obj->get_width() / 2;
    rect1.y = obj->get_y() - obj->get_height() / 2;
    rect1.width = obj->get_width();
    rect1.height = obj->get_height();

    // Ball rect
    Rectangle rect2;
    rect2.x = next_x - this->width / 2;
    rect2.y = next_y - this->height / 2;
    rect2.width = this->width;
    rect2.height = this->height;

    float angle = atan2(
      rect2.y - rect1.y, 
      rect2.x - rect1.x) 
      * 180 / M_PI;
    if (rect_intersect(rect1, rect2))
    {
      std::cout << angle << "\n";
      this->direction = -angle;
      return;
    }

  }

  this->x += dx;
  this->y += dy;
}