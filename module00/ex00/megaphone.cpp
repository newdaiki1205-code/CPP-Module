/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:17:47 by dshirais          #+#    #+#             */
/*   Updated: 2026/07/13 19:12:52 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

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
            if(!std::isprint(av[i][j]))
            {
                std::cout << "Invalid Output:It includes non-printable character." << std::endl;
                return 1;
            }
            j++;
        }       
        i++;
    }

    i = 1;

    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            std::cout << (char) std::toupper(av[i][j]);
            j++;
        }       
        i++;
    }
    std::cout << std::endl;
    return 0;
}
