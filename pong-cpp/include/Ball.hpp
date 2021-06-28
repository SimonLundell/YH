#ifndef BALL_H
#define BALL_H

#include "GameObject.hpp"

class Ball : public GameObject {
    public:
        Ball(float x, float y);

    private:
        unsigned int red{};
        unsigned int green{};
        unsigned int blue{};
};

#endif