/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:01:31 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/24 14:42:34 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"
#include <iostream>
#include <sstream>

StackMachine::StackMachine() {
  std::cout << "Default Constructor called" << std::endl;
}

StackMachine::~StackMachine() { std::cout << "Destructor called" << std::endl; }

StackMachine::StackMachine(const StackMachine &other) {
  std::cout << "Copy Constructor called" << std::endl;
  _stack = other._stack;
}

StackMachine &StackMachine::operator=(const StackMachine &other) {
  std::cout << "Copy Assignment operator called" << std::endl;
  if (this == &other)
    return *this;
  _stack = other._stack;
  return *this;
}

int StackMachine::calculation(char *str) {
  std::string rawData(str);
  std::istringstream input(rawData);
  std::string tmp;
  int digit;

  while (input) {
    input >> tmp;
    if (tmp.length() != 1) {
      if (tmp.length() != 2)
        throw InvalidCharacterInput();
      if (tmp[0] != '-' && tmp[0] != '+')
        throw InvalidCharacterInput();
    }
  }
  return (_stack.top());
}
