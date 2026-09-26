/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:16:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/24 15:06:03 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "../include/RPN.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Invalid Input: Please give only one argument" << std::endl;
    return 1;
  }
  if (!av[1] || !*av[1]) {
    std::cerr << "Invalid Input: Please give only one argument" << std::endl;
    return 1;
  }
  try {
    StackMachine a;
    a.calculation(av[1]);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
