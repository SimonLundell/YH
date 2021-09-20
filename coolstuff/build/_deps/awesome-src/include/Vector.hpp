#ifndef AWESOME_VECTOR_H
#define AWESOME_VECTOR_H

namespace Awesome
{
    class Vector
    {
        public:
            Vector(float x, float y, float z);

            float get_x();
            float get_y();
            float get_z();

            void set_x(float x);
            void set_y(float y);
            void set_z(float z);

        private:
            float x;
            float y;
            float z;

    };
} // Awesome

#endif