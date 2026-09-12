/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:12:09 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/11 17:09:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/Base.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <exception>

Base::~Base(){}

Base* generate(void)
{
  int i;
  Base* res;
  
  srand(time(0));
  i = rand() % 3;
  switch (i)
  {
    case 0:
      res = new A();
      break;
    case 1:
      res = new B();
      break;
    case 2:
      res = new C();
      break;
    default:
      std::cout << "Error in generate()" << std::endl;
      exit(1);
  }
  return res;
}

void identify(Base* p)
{
  std::cout << "this is test for pointer" << std::endl;

  if(dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if(dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if(dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Type not identified" << std::endl;
}

void identify(Base& p)
{
  std::cout << "this is test for reference" << std::endl;
  try
  {
    A& aref = dynamic_cast<A&>(p);
    (void)aref;
    std::cout << "A" << std::endl;
    return;
  }
  catch(std::exception &e)
  {
  }
  try
  {
    B& bref = dynamic_cast<B&>(p);
    (void)bref;
    std::cout << "B" << std::endl;
    return;
  }
  catch(std::exception &e)
  {
  }
  try
  {
    C& cref = dynamic_cast<C&>(p);
    (void)cref;
    std::cout << "C" << std::endl;
    return ;
  }
  catch(std::exception &e)
  {
    std::cout << "Type not identified" << std::endl;
  }
}
