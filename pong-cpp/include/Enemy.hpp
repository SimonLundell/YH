#ifndef ENEMY_H
#define ENEMY_H
#include "Pad.hpp"

class Enemy : public Pad {
    public:
        Enemy(float x, float y);

        void update();
        void draw();
};

#endif