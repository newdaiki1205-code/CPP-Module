/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:18:16 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:18:17 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_info()
{
    std::string info[5];

    std::cout << "First Name: ";
    std::getline(std::cin, info[0]);
    std::cout << "Last Name: ";
    std::getline(std::cin, info[1]);
    std::cout << "Nick Name: ";
    std::getline(std::cin, info[2]);
    std::cout << "Phone Number: ";
    std::getline(std::cin, info[3]);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, info[4]);;

    fill_info(info);
}

void PhoneBook::fill_info(std::string (&info)[5])
{
    int pos = this->i % 8;
     
    this->array[pos].setFirstName(info[0]);
    this->array[pos].setLastName(info[1]);
    this->array[pos].setNickName(info[2]);
    this->array[pos].setPhoneNum(info[3]);
    this->array[pos].setDarkerSecret(info[4]);
    this->i++;
}

void PhoneBook::search_info()
{
    int index = 0;
    std::string info[5];
    std::string first;
    std::string last;
    std::string nick;
    std::string input;

    
    if(this->i == 0)
    {
        std::cout << "Phone Box is empty" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nick Name" << std::endl;
    
    while(index < 8 && index < this->i)
    {
        std::cout << std::setw(10) << index << "|";
        display_subinfo(this->array[index].getFirstname());
        std::cout << "|";
        display_subinfo(this->array[index].getLastname());
        std::cout << "|";
        display_subinfo(this->array[index].getNickname());
        std::cout << std::endl;
        index++;
    }

    std::cout << std::endl;
    std::cout << "Enter Index: ";
    std::getline(std::cin, input);
    if(input < "0" || input > "7")
    {
        std::cout << "Invalid Input: Index should be between 0 and 7" << std::endl;
        return;
    }
    index = std::atoi(input.c_str());
    if(index > this->i)
    {
        std::cout << "No Information" << std::endl;
        return;
    }
    std::cout << "First Name: " << this->array[index].getFirstname() << std::endl;
    std::cout << "Last Name: " << this->array[index].getLastname() << std::endl;
    std::cout << "Nick Name: " << this->array[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->array[index].getPhoneNum() << std::endl;
    std::cout << "Darkest Secret: " << this->array[index].getDarkestSec() << std::endl;
}

void PhoneBook::display_subinfo(std::string src)
{
    if(src.length() <= 10)
        std::cout << std::setw(10) << src;
    else
        std::cout << std::setw(10) << src.substr(0, 9) + ".";
}