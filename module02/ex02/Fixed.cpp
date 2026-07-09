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
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
    :value(number << bits)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
    :value(roundf(number * (1 << bits)))
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
    :value(other.getRawBits())
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>(const Fixed& other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed tmp;

    tmp.value = this->getRawBits() + other.getRawBits();
    return tmp;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed tmp;

    tmp.value = this->getRawBits() - other.getRawBits();
    return tmp;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed tmp;

    tmp.value = this->getRawBits() * other.getRawBits() >> bits;
    return tmp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed tmp;

    tmp.value = this->getRawBits() / other.getRawBits() << bits;
    return tmp;
}

Fixed& Fixed::operator++()
{
    value = value + 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;

    operator++();
    return old;
}

Fixed& Fixed::operator--()
{
    value = value - 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;

    operator--();
    return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}