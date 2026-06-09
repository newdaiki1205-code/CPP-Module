/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:58:20 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/09 17:15:57 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieArray;

    zombieArray = new Zombie[N];
    for(int i = 0; i < N ; i++)
        zombieArray[i].setName(name);
    return zombieArray;
}