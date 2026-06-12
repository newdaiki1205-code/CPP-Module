/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:09:49 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 16:28:07 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    typedef void(Harl::*ptrToFunc)(void);
    ptrToFunc ptrArray[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while(i < 4 && level.compare(levelArray[i]))
        i++;
    switch (i)
    {
        case 0:
            (this->*ptrArray[i++])();
        case 1:
            (this->*ptrArray[i++])();
        case 2:
            (this->*ptrArray[i++])();
        case 3:
            (this->*ptrArray[i++])();
            break;
        default:
            std::cout << "Invalid level: Level should be DEBUG, INFO, WARNING, or ERROR" << std::endl;
            break;
    }
}

void Harl::debug(void)
{
    std::cout 
        << "[ DEBUG ]\n"
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
        << std::endl;
}

void Harl::info(void)
{
    std::cout
        << "[ INFO ]\n"
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
        << std::endl;
}

void Harl::warning(void)
{
    std::cout
        << "[ WARNING ]\n"
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n"
        << std::endl;
}

void Harl::error(void)
{
    std::cout
        << "[ ERROR ]\n"
        << "This is unacceptable! I want to speak to the manager now.\n"
        << std::endl;
}

