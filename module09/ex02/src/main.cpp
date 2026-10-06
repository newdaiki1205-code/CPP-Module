/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 00:04:30 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/10/03 00:11:19 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "Error: too little argument" << std::endl;
    std::cout << "Format: ./PmergeMe [number1] [number2] ..." << std::endl;
    return 1;
  }
  try {
    PMerge a;
    a.PmergeMe(av);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
