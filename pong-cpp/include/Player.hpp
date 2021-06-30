#ifndef PLAYER_H
#define PLAYER_H
#include "Pad.hpp"

class Player : public Pad {
    public:
        Player(float x, float y);

        void update();
        void draw();
};

#endif