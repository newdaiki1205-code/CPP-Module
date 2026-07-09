/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:00:11 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/15 19:15:08 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed()
    :value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
    :value(number << bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
    :value(roundf(number * (1 << bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
    :value(other.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return value;
}

void Fixed::setRawBits( int const raw )
{
    value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
    out << c.toFloat();
    return out;
}

int Fixed::toInt( void ) const
{
    return value >> bits;
}

float Fixed::toFloat( void ) const
{
    return (float)value/(float)(1 << bits);
}