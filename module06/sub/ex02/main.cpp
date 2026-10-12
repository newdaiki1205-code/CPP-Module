/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:44:29 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/12 11:46:12 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
  std::srand(std::time(0));

  for (int i = 0; i < 6; i++) {
    std::cout << "=== test" << i + 1 << " ===" << std::endl;
    Base *test = generate();
    std::cout << "pass Base*: ";
    identify(test);
    std::cout << "pass Base&: ";
    identify(*test);
    delete test;
  }

  return 0;
}
