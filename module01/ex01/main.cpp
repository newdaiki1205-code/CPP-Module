/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:16:17 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/09 17:23:29 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
    Zombie *testArray;

    testArray = zombieHorde(3, "Foo");
    for(int i = 0; i < 3 ; i++)
        testArray[i].announce();
    delete testArray;
    return 0;
}