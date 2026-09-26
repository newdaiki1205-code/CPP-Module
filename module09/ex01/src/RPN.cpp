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

#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

StackMachine::StackMachine() {}

StackMachine::~StackMachine() {}

StackMachine::StackMachine(const StackMachine& other) { _stack = other._stack; }

StackMachine& StackMachine::operator=(const StackMachine& other) {
  if (this == &other) return *this;
  _stack = other._stack;
  return *this;
}

void StackMachine::calculation(std::string rawData) {
  std::istringstream input(rawData);
  std::string tmp;
  int input_flag;

  while (input) {
    input >> tmp;
    if (!input) break;
    input_flag = inputChecker(tmp);
    if (!input_flag) {
      _stack.push(std::atoi(tmp.c_str()));
    } else {
      if (_stack.size() < 2) throw InvalidOrderInput();
      operation(tmp);
    }
  }
  if (_stack.size() != 1) throw InvalidOrderInput();
  std::cout << _stack.top() << std::endl;
}

void StackMachine::operation(std::string _operator) {
  int i = operatorIdentify(_operator);
  long right = _stack.top();
  _stack.pop();
  long left = _stack.top();
  _stack.pop();
  long res;

  switch (i) {
    case 0:
      res = left + right;
      break;
    case 1:
      res = left - right;
      break;
    case 2:
      res = left * right;
      break;
    case 3:
      if (right == 0) throw DevidedByZero();
      res = left / right;
      break;
    default:
      throw std::logic_error("Unknown Error");
  }
  if (std::numeric_limits<int>::min() > res ||
      std::numeric_limits<int>::max() < res)
    throw std::overflow_error("Error: Stack<int> overflow!");
  _stack.push(res);
}

int StackMachine::inputChecker(std::string input) {
  if (input.length() > 2) throw InvalidCharacterInput();
  if (input.length() == 2) {
    if (input[0] != '-' && input[0] != '+') throw InvalidCharacterInput();
    if (!std::isdigit(input[1])) throw InvalidCharacterInput();
    return (0);
  }
  if (!std::isdigit(input[0])) {
    if (operatorIdentify(input) < 0) throw InvalidCharacterInput();
    return (1);
  }
  return (0);
}

int StackMachine::operatorIdentify(std::string input) {
  std::string operators = "+-*/";
  for (int i = 0; i < 4; i++) {
    if (input.find(operators[i]) != std::string::npos) return (i);
  }
  return (-1);
}

const char* StackMachine::InvalidCharacterInput::what() const throw() {
  return "Invalid Input: Only digit and operator (+-*/) valid";
}

const char* StackMachine::InvalidOrderInput::what() const throw() {
  return "Invalid Input: Check the order of input";
}

const char* StackMachine::DevidedByZero::what() const throw() {
  return "Error: Dividing by zero occured";
}
