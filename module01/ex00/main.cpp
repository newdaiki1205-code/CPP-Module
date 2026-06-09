/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:56:40 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/09 16:28:19 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *tmp;

    randomChump("Foo");
    tmp = newZombie("Wild");
    tmp->announce();
    delete tmp;
    return 0;
}