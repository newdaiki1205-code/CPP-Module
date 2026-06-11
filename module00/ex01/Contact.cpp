/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:17:54 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:17:55 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string fn)
{
    this->FirstName = fn;
}

void Contact::setLastName(std::string ln)
{
    this->LastName = ln;
}

void Contact::setNickName(std::string nick)
{
    this->NickName = nick;
}

void Contact::setPhoneNum(std::string pn)
{
    this->PhoneNum = pn;
}

void Contact::setDarkerSecret(std::string ds)
{
    this->DarkestSecret = ds;
}

std::string Contact::getFirstname()
{
    return this->FirstName;
}

std::string Contact::getLastname()
{
    return this->LastName;
}

std::string Contact::getNickname()
{
    return this->NickName;
}

std::string Contact::getPhoneNum()
{
    return this->PhoneNum;
}

std::string Contact::getDarkestSec()
{
    return this->DarkestSecret;
}
