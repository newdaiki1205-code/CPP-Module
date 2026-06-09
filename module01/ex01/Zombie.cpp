/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:15:24 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/09 17:10:20 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string given)
{
    name = given;
}

Zombie::~Zombie()
{
    std::cout << name << std::endl;
};

void Zombie::announce( void )
{
   std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
 
void Zombie::setName(std::string given)
{
    name = given;
}