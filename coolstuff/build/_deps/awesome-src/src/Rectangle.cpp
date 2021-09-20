//#include "../include/Rectangle.hpp"
#include <Rectangle.hpp>

Awesome::Rectangle::Rectangle(float width, float height) : width(width), height(height)
{

}

float Awesome::Rectangle::get_area()
{
    return this->width * this->height;
}