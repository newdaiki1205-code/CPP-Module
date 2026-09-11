/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 14:37:49 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/11 14:38:12 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <iostream>

int main(void)
{
  Data *test = new Data();
  test->num = 42;

  std::cout << "ptr: "<< test << " num: " << test->num << std::endl;
  std::cout 
    << "Serialize and Deserialize\n" 
    << "ptr: "
    << Serializer::deserialize(Serializer::serialize(test))
    << " num: "
    << Serializer::deserialize(Serializer::serialize(test))->num << std::endl;

  delete test;

  return 0;

}
