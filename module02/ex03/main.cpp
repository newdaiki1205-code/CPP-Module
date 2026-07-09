#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    std::cout << "---------------" << std::endl;
    std::cout << "Subject Example" << std::endl;
    std::cout << "---------------" << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << "Additional Test" << std::endl;
    std::cout << "---------------" << std::endl;

    Fixed c(10);
    Fixed d(5);
    Fixed e(0.5f);

    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "e is " << e << std::endl;
    std::cout << std::endl;
    std::cout << "c+d is " << c+d << std::endl;
    std::cout << "c-d is " << c-d << std::endl;
    std::cout << "c*d is " << c*d << std::endl;
    std::cout << "c/d is " << c/d << std::endl;
    std::cout << "c+e is " << c+e << std::endl;
    std::cout << "c-e is " << c-e << std::endl;
    std::cout << "c*e is " << c*e << std::endl;
    std::cout << "c/e is " << c/e << std::endl;
    std::cout << std::endl;
    std::cout << "c == d is ";
    if(c == d)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    std::cout << "c != e is ";
    if(c != e)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    std::cout << "(c * e) == d is ";
    if(c * e == d)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    std::cout << std::endl;
    std::cout << "c++ is " << c++ << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "c-- is " << c-- << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << std::endl;
    std::cout << "Comparing the value of c and d, the greatest value is " << Fixed::max( c, d ) << std::endl;
    std::cout << "Comparing the value of c and e, the smallest value is "<< Fixed::min( d, e ) << std::endl;

    return 0;
}
