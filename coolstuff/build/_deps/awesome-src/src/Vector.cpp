#include <Vector.hpp>

Awesome::Vector::Vector(float x, float y, float z) : x(x), y(y), z(z)
{

}
float Awesome::Vector::get_x()
{
    return this->x;
}
float Awesome::Vector::get_y()
{
    return this->y;
}
float Awesome::Vector::get_z()
{
    return this->z;
}
void Awesome::Vector::set_x(float x)
{
    this->x = x;
}
void Awesome::Vector::set_y(float y)
{
    this->x = y;
}
void Awesome::Vector::set_z(float z)
{
    this->x = z;
}