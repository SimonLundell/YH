#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
class GameObject {
  public:
    GameObject(float x, float y);

    virtual void update() = 0;
    virtual void draw() = 0;

  protected:
    float x;
    float y;
    float width;
    float height;
    float dx;
    float dy;
};
#endif
