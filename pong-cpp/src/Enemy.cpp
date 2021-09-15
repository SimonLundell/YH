#include "Enemy.hpp"
#include <Ball.hpp>
#include <Game.hpp>
#include <Math.hpp>

extern Game* game;

Enemy::Enemy(float x, float y) : Pad(x,y), target_x(0), target_y(0), target_dx(0), target_dy(0) {
    
}

void draw_line(float x, float y, float x2, float y2)
{
  SDL_Renderer* renderer = game->get_renderer();

  SDL_SetRenderDrawColor(renderer, 255,0,0,1);
  SDL_RenderDrawLine(renderer, x,y,x2,y2);
  SDL_SetRenderDrawColor(renderer,0,0,0,1);
}

void Enemy::draw() {
    this->draw_default();
    draw_line(this->get_x(), this->get_y() + this->get_height() / 2, this->target_dx, this->target_dy);
}


void Enemy::update() {

  float speed = 8.0f;
  float eye_speed = 8.0f;

  Ball* ball = 0;
  std::vector<GameObject*> objects = game->get_game_objects();

  // search for the ball
  for (std::vector<GameObject*>::iterator it = objects.begin(); it != objects.end(); it++) {
    GameObject* obj = *it;
    if (dynamic_cast<Ball*>(obj) != nullptr) {
      // found the ball
      ball = (Ball*)obj;
      break;
    }
  }

  float bottom_y = this->get_y() + this->get_height() - 8;
  float top_y = this->get_y() + 8;
  float cx = this->get_x() + this->get_width() / 2;

  int chance = 3;
  if (ball && random_range(0,chance) >= chance - 1) 
  {
    target_y = ball->get_y() + ball->get_width() / 2;
    target_x = ball->get_x() + ball->get_height() / 2;
  }


  if (target_dy < target_y) 
  {
    target_dy += eye_speed;
  } 
  else if (target_dy > target_y) 
  {
    target_dy -= eye_speed;
  }

  if (target_dx < target_x) 
  {
    target_dx += eye_speed;
  } 
  else if (target_dx > target_x) 
  {
    target_dx -= eye_speed;
  }

  if (bottom_y < target_dy)
  {
    this->y += speed;
  }
  if (top_y > target_dy)
  {
    this->y -= speed;
  }

  /*
  if (this->y < target_dy) 
  {
    this->y += speed;
  } else 
  {
    this->y -= speed;
  }
  */
}