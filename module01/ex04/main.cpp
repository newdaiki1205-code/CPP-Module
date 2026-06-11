/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:27:21 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 15:44:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filemanage.hpp"

int input_check(int ac, char **av);

int main (int ac, char **av)
{
    if(input_check(ac, av))
        return 1;
    
    Filemanager fm(av[1], av[2], av[3]);
    
    std::ifstream inFile(av[1]);
    if(!inFile.is_open())
    {
        std::cout << "Error opening file for reading." << std::endl;
        return 1;
    }
    
    std::ofstream outFile(fm.getFilename());
    if(!outFile.is_open())
    {
        std::cout << "Error opening file for writing." << std::endl;
        inFile.close();
        return 1;
    }

    fm.rewrite(inFile, outFile);
    inFile.close();
    outFile.close();
    return 0;
}

int input_check(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "Invalid input: Give a filename and two strings" << std::endl;
        return 1;
    }
    if(!av[1] || !*av[1] || !*av[2] || !*av[3])
    {
        std::cout << "Invalid input: Give a filename and two strings" << std::endl;
        return 1;
    }
    return 0;
}