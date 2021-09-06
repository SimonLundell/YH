#include <Collision.hpp>
#include <sys/param.h>
#include <vector>
#include <Pad.hpp>

bool is_rectangle_colliding(Rectangle rect, Vec2d vec) {

  bool x_touching = (vec.x >= rect.x - (rect.width) &&
                     vec.x <= (rect.x + (rect.width)));

  bool y_touching = (vec.y >= rect.y - (rect.height) &&
                     vec.y <= (rect.y + (rect.height)));

  return x_touching && y_touching;
}

bool rect_intersect(Rectangle rect1, Rectangle rect2)
{
   return (rect1.x + rect1.width >= rect2.x && rect1.x <= rect2.x + rect2.width) &&
      (rect1.y + rect1.height >= rect2.y && rect1.y <= rect2.y + rect2.height);
}

bool get_collision_point(Game* game, GameObject* us, float xa, float ya, CollisionPoint* point) {
  std::vector<GameObject*> objects = game->get_game_objects();
  std::vector<GameObject*>::iterator it;

  for (it = objects.begin(); it != objects.end(); it++){
      GameObject* obj = *it;

      if (dynamic_cast<Pad*>(obj) == nullptr)
        continue;

        if ((us->get_x()+xa) + us->get_width() >= obj->get_x() && (us->get_x()+xa) <= obj->get_x() + obj->get_width()) {
        if ((us->get_y()+ya) + us->get_height() >= obj->get_y() && (us->get_y()+ya) <= obj->get_y() + obj->get_height()) {
          point->point.x = MAX(us->get_x() + xa, obj->get_x()) - MIN(us->get_x() + xa, obj->get_x());
          point->point.y =  MAX(us->get_y() + ya, obj->get_y()) - MIN(us->get_y() + ya, obj->get_y());
          point->obj = obj;

          return true;
        }
      }
  }

  return false;
}