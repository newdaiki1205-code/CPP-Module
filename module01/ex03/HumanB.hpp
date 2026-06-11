/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:19:10 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:19:11 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name)
            :personName(name){};
        ~HumanB(){};
        void attack();
        void setWeapon(Weapon &weapon);
    
    private:
        Weapon *weaponType;
        std::string personName;
};

#endif

