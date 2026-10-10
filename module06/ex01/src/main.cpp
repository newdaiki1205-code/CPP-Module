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

int main(void) {
  Data *a = new Data();
  a->num = 42;
  Data *b = Serializer::deserialize(Serializer::serialize(a));

  if (a == b) {
    std::cout << "Comparison Test Passed!" << std::endl;
    std::cout << "original: " << a << "(value: " << a->num << ")" << std::endl;
    std::cout << "deserialized: " << b << "(value: " << b->num << ")"
              << std::endl;
  } else {
    std::cout << "Comparison Test Failed..." << std::endl;
  }

  delete a;

  return 0;
}
