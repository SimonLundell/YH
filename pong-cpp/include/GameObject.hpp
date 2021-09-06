#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
class GameObject {
  public:
    GameObject(float x, float y);

    virtual void update() = 0;
    virtual void draw() = 0;

    float get_x();
    float get_y();
    float get_width();
    float get_height();
    void push(float direction, float speed);

  protected:
    float x;
    float y;
    float width;
    float height;
    float dx;
    float dy;
    float speed;
};
#endif
