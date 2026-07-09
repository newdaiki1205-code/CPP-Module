/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:00:08 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/15 19:06:31 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();    

        Fixed(const int number);
        Fixed(const float number);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif