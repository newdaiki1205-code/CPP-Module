/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:19:06 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:19:07 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << personName << " attacks with their " << weaponType->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    weaponType = &weapon;
}