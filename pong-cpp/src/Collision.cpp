#include "Collision.hpp"

bool is_rectangle_colliding(Rectangle rect, Vec2d vec)
{
   bool x_touching = (vec.x >= rect.x-(rect.width/2) && vec.x <= (rect.x + (rect.width/2)));

   bool y_touching = (vec.y >= rect.y-(rect.height/2) && vec.y <= (rect.y + (rect.height/2)));

   return x_touching && y_touching; 
}
