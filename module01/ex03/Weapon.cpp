/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:19:20 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:19:21 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    type = weapon;
}

const std::string& Weapon::getType()
{   
    return type;
}

void Weapon::setType(std::string str)
{
    type = str;
}