#include "BSP.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    int a_to_b = cross(a, b, point);
    int b_to_c = cross(b, c, point);
    int c_to_a = cross(c, a, point);

    if(a_to_b > 0 && b_to_c > 0 && c_to_a > 0)
        return true;
    else if(a_to_b < 0 && b_to_c < 0 && c_to_a < 0)
        return true;
    else
        return false;
}

float cross(Point base, Point dir, Point target)
{
    float base_x = base.getval_x().toFloat();
    float base_y = base.getval_y().toFloat();
    float dir_x = dir.getval_x().toFloat();
    float dir_y = dir.getval_y().toFloat();
    float target_x = target.getval_x().toFloat();
    float target_y = target.getval_y().toFloat();
    
    return ((dir_x - base_x) * (target_y - base_y) - (dir_y - base_y) * (target_x - base_x));
}
