#include "Point.hpp"

Point::Point()
    : x(0), y(0){};

Point::Point(const Point& other)
    : x(other.getval_x()), y(other.getval_y()){};


// Point& operator=(const Point& other);
Point::~Point(){};

Point::Point(float val_x, float val_y)
    :x(val_x), y(val_y){};

Fixed const Point::getval_x()
{
    return this->x;
}

Fixed const Point::getval_y()
{
    return this->y;
}