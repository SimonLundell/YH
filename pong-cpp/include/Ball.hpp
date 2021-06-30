#ifndef BALL_H
#define BALL_H
#include <GameObject.hpp>
#include <Draw.hpp>

class Ball : public GameObject {
  public:
    Ball(float x, float y);

    void update();
    void draw();

  private:
    unsigned int red;
    unsigned int green;
    unsigned int blue;
};

#endif
