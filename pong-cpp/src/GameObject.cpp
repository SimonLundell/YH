#include <GameObject.hpp>

GameObject::GameObject(float x, float y) : 
x(x), y(y), dx(0), dy(0) {
}

float GameObject::get_x()
{
    return this->x;
}
float GameObject::get_y()
{
    return this->y;
}
float GameObject::get_width()
{
    return this->width;
}
float GameObject::get_height()
{
    return this->height;
}
