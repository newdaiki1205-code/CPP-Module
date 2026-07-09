#ifndef BSP_HPP
# define BSP_HPP

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);
float cross(Point base, Point dir, Point target);

#endif