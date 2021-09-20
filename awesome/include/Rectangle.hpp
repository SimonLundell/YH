#ifndef AWESOME_RECTANGLE_H
#define AWESOME_RECTANGLE_H

namespace Awesome
{
    class Rectangle
    {
        public:
            Rectangle(float width, float height);

            float get_area();

        private:
            float width;
            float height;
    };
} // Awesome

#endif