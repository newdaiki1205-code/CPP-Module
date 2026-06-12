/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:09:51 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 16:17:24 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
    public:
        Harl(){};
        ~Harl(){};
        void complain( std::string level );
        
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif