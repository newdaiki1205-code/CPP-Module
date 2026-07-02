/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:18:12 by dshirais          #+#    #+#             */
/*   Updated: 2026/07/02 16:44:52 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "General.hpp"
#include "PhoneBook.hpp"

int main()
{   
    std::string input;
    PhoneBook myPhoneBook;

    std::cout << "My Awsome Phone Book is opened!" << std::endl;

    while(1)
    {
        std::cout << "Enter Your Command(ADD, SEARCH, or EXIT): ";
        // if (!std::getline(std::cin, input))
        //     break;

        std::getline(std::cin, input);
        if(std::cin.eof() == 1)
        {
            // std::cin.clear();
            // std::cin.ignore ();
            // std::cout << "EOF" << std::endl;
            break;
        }
            
        if(!input.compare("ADD"))
            myPhoneBook.add_info();
        else if (!input.compare("SEARCH"))
            myPhoneBook.search_info();
        else if (!input.compare("EXIT"))
            break;
        std::cout << std::endl;
    }

    std::cout << "My Awsome Phone Book is closed!" << std::endl;
    return 0;
}