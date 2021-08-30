#include "Keyboard.hpp"


bool Keyboard::is_key_pressed(int key)
{
    return this->keys[key] != 0;
}

void Keyboard::set_key(int key, int toggle)
{
    this->keys[key] = toggle;
}