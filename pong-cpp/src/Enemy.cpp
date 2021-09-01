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
    float eye_speed = 0.001f;
    float friction = 0.09f;

    Ball* ball = nullptr;
    std::vector<GameObject*> objects = game->get_game_objects();
    
    // search for the ball
    for (auto &obj : objects)
    {
        if (dynamic_cast<Ball*>(obj) != nullptr)
        {   // Found the ball
            ball = (Ball*)obj;
            break;
        }   
    }

    if (ball) {
        target_x = ball->get_x();
        target_y = ball->get_y();
    }

    if (this->target_dy < target_y) {
        this->target_dy += speed;
    }
    if (this->target_dy > target_y) {
        this->target_dy -= speed;
    }

    if (this->target_dy > 0)
    {
        if (this->target_dy - friction >= 0)
        {
            this->target_dy -= friction;
        } 
        else 
        {
            this->target_dy = 0;
        }
    } 
    else 
    {
        if (this->target_dy + friction <= 0)
        {
            this->target_dy += friction;
        } 
        else 
        {
            this->target_dy = 0;
        }
    }

    this->y += speed;
}