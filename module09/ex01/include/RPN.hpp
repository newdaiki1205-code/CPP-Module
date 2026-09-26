/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 22:42:50 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/24 15:05:59 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <exception>
#include <list>
#include <stack>
#include <string>

class StackMachine {
 private:
  std::stack<int, std::list<int> > _stack;
  static int inputChecker(std::string input);
  void operation(std::string _operator);
  static int operatorIdentify(std::string input);

 public:
  StackMachine();
  ~StackMachine();
  StackMachine(const StackMachine& other);
  StackMachine& operator=(const StackMachine& other);

  void calculation(std::string rawData);

  class InvalidCharacterInput : public std::exception {
    const char* what() const throw();
  };

  class InvalidOrderInput : public std::exception {
    const char* what() const throw();
  };

  class DevidedByZero : public std::exception {
    const char* what() const throw();
  };
};

#endif  // !RPN_HPP
