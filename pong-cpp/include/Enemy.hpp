#ifndef ENEMY_H
#define ENEMY_H
#include "Pad.hpp"

class Enemy : public Pad {
    public:
        Enemy(float x, float y);

        void update();
        void draw();
    
    private:
        float target_y;
        float target_x;
        float target_dy;
        float target_dx;
};

#endif