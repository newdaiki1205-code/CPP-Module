#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        Point(float val_x, float val_y);
        Fixed const getval_x();
        Fixed const getval_y();
};

#endif