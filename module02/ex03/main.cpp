#include "Fixed.hpp"
#include "Point.hpp"
#include "BSP.hpp"
#include <iostream>

int main( void ) 
{
    Point a(0.5f, 1.2f);
    Point b(5.8f, 0.3f);
    Point c(3.1f, 6.4f);
    Point p(3.15f, 0.633f);

    std::cout << "a is (" << a.getval_x() << "," << a.getval_y() << ")." << std::endl;
    std::cout << "b is (" << b.getval_x() << "," << b.getval_y() << ")." << std::endl;
    std::cout << "c is (" << c.getval_x() << "," << c.getval_y() << ")." << std::endl;
    std::cout << "p is (" << p.getval_x() << "," << p.getval_y() << ")." << std::endl;


    if(bsp(a, b, c, p))
        std::cout << "p is inside." << std::endl;
    else
        std::cout << "p is outside." << std::endl;

    return 0;
}
