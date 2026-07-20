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

int N = 10;

int main (void)
{
    Zombie *testArray;

    testArray = zombieHorde(N, "Foo");
    for(int i = 0; i < N ; i++)
        testArray[i].announce();
    delete[] testArray;
    return 0;
}
