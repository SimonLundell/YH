#include "Enemy.hpp"
#include <Ball.hpp>
#include <Game.hpp>

extern Game* game;

Enemy::Enemy(float x, float y) : Pad(x,y), target_x(0), target_y(0), target_dx(0), target_dy(0) {
    
}

void Enemy::draw() {
    this->draw_default();
}

void Enemy::update() {

  float speed = 0.1f;
  float eye_speed = 0.1f;

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

  if (ball) {
    target_y = ball->get_y();
  }


  if (target_dy < target_y) {
    target_dy += eye_speed;
  } else if (target_dy > target_y) {
    target_dy -= eye_speed;
  }

  if (this->y < target_dy) {
    this->y += speed;
  } else {
    this->y -= speed;
  }
}