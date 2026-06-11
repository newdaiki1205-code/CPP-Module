/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:19:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:19:03 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon)
            :weaponType(weapon), personName(name){};
        ~HumanA(){};
        void attack();
    
    private:
        Weapon &weaponType;
        std::string personName;
};

#endif