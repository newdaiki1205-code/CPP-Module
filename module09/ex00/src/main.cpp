/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:22:46 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/30 14:41:24 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  if (!av[1] || !*av[1]) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  BitcoinExchange a;
  try {
    a.exchange(av[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
