/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:17:47 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:17:48 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int main(int ac, char **av)
{
    int i = 1;
    int j;

    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
        return 0;
    }

    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            std::cout << (char) toupper(av[i][j]);
            j++;
        }       
        i++;
    }
    std::cout << std::endl;
    return 0;
}
