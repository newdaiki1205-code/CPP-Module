/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:29:03 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/11 14:38:34 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other)
{
  (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
  if(this == &other)
    return (*this);
  return (*this);
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
  return reinterpret_cast<Data*>(raw);
}

