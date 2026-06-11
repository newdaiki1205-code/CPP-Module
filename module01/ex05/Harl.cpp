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
    Harl tmp;
    (void)level;
    void(Harl::*ptrtodebug)(void) = &Harl::debug;
    (tmp.*ptrtodebug)();
}

void Harl::debug(void)
{
    std::cout 
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
}

void Harl::info(void)
{
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning(void)
{
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
        << std::endl;
}

void Harl::error(void)
{
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

