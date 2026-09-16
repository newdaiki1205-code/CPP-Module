/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:16:58 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/16 16:55:28 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main(void)
{
  std::cout << "Test1: Default Construction and set values, throwing exception" << std::endl;
  try 
  {
    Array<int> a;
    std::cout << "size: " << a.size() << std::endl;
    a.set(1, 0);
    std::cout << a.get(0) << std::endl;
  }
  catch (const std::exception& e) 
  {
    std::cout << "Invalid Access" << std::endl;
  }
  std::cout << "-------------------------------------------------------------" << std::endl;

  std::cout << "Test2: Construction with parameter and set values" << std::endl;
  try
  {
    Array<int> b(5);
    std::cout << "size: " << b.size() << std::endl;
    std::cout << "Check Default Values" << std::endl;
    for(int i = 0; i < 5; i++)
      std::cout << b.get(i) << " ";
    std::cout << std::endl;
    for(int i = 0; i < 5; i++)
      b.set(i, i);
    std::cout << "Check Values after set" << std::endl;
    for(int i = 0; i < 5; i++)
      std::cout << b.get(i) << " ";
    std::cout << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cout << "Invalid Access" << std::endl;
  }
  std::cout << "-------------------------------------------------------------" << std::endl;

  std::cout << "Test3: Construction with parameter and access to out of range" << std::endl;
  try
  {
    Array<float> c(5);
    std::cout << "size:" << c.size() << std::endl;
    std::cout << "Access index 100" << std::endl;
    c.get(100);
  }
  catch(const std::exception& e)
  {
    std::cout << "Invalid Access" << std::endl;
  }
  std::cout << "-------------------------------------------------------------" << std::endl;

  std::cout << "Test4: Copy Construction" << std::endl;
  try
  {
    Array<int> d(5);
    for(int i = 0; i < 5; i++)
      d.set(i, i);
    std::cout << "Check parent's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << d.get(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    Array<int> e(d);
    std::cout << "Check child's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << e.get(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Modify parent's value" << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < 5; i++)
      d.set(i * 10, i);
    std::cout << "Check parent's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << d.get(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Check child's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << e.get(i) << " ";
    std::cout << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cout << "Invalid Access" << std::endl;
  }
  std::cout << "-------------------------------------------------------------" << std::endl;

  std::cout << "Test5: Copy Assignment Operator" << std::endl;
  try
  {
    Array<double> f;

    if(1)
    {
      Array<double> g(5);
      for(int i = 0; i < 5; i++)
        g.set(100 * i, i);
      std::cout << "Check parent's value" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << g.get(i) << " ";
      std::cout << std::endl;

      std::cout << std::endl;

      f = g;

      std::cout << "Check child's value" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << f.get(i) << " ";
      std::cout << std::endl;

      std::cout << std::endl;
      std::cout << "Delete parent" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Check child's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << f.get(i) << " ";
    std::cout << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cout << "Invalid Access" << std::endl;
  }
  return 0;
}
