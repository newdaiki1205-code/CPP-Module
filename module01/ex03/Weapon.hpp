/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:19:23 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:19:24 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
    public:
        Weapon(){};
        Weapon(std::string weapon);
        ~Weapon(){};
        const std::string &getType();
        void setType(std::string str);

    private:
        std::string type;
};

#endif