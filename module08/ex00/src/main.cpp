/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 08:19:59 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/18 08:20:55 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime> 

int main(void)
{
  std::cout << "Test1: Simple vector and Error test" << std::endl;
  try 
  {
    std::vector<int> a;
    std::cout << "Create vector (0-4)" << std::endl;
    for(int i = 0; i < 5; i++)
      a.push_back(i);
    easyfind(a, 1);
    std::cout << std::endl;
    std::cout << "Reverse Sort" << std::endl;
    std::sort(a.rbegin(), a.rend());
    easyfind(a, 1);
    std::cout << std::endl;
    std::cout << "Change values (5-9)" << std::endl;
    for(int i = 0; i < 5; i++)
      a.at(i) = i + 5;
    easyfind(a, 1);
  }
  catch (const std::exception& e) 
  {
    std::cout << "Not found..." << std::endl;
  }
  std::cout << "---------------------------------------------------------------------" << std::endl;

  std::cout << "Test2: Simple list and Error test" << std::endl;
  try
  {
    std::list<int> b;
    std::cout << "Create list (0-4)" << std::endl;
    for(int i = 0; i < 5; i++)
      b.push_back(i);
    easyfind(b, 4);
    std::cout << std::endl;
    std::cout << "Delete elements and insert the same values in opposit oder" << std::endl;
    for(int i = 0; i < 5; i++)
      b.pop_back();
    if(b.empty())
      std::cout << "list is empty" << std::endl;
    for(int i = 0; i < 5; i++)
      b.push_front(i);
    easyfind(b, 4);
    std::cout << std::endl;
    std::cout << "Delete the first value(4)" << std::endl;
    b.pop_front();
    easyfind(b, 4);
  }
  catch(const std::exception& e)
  {
    std::cout << "Not found..." << std::endl;
  }
  std::cout << "---------------------------------------------------------------------" << std::endl;

  std::cout << "Test3: Check if easyfind finds the first occurrence" << std::endl;
  try
  {
    std::vector<int> c;
    std::cout << "Create vector (0-4)" << std::endl;
    for(int i = 0; i < 5; i++)
      c.push_back(i);
    std::cout << "Add 1 at the last" << std::endl;
    c.push_back(1);
    easyfind(c, 1);
  }
  catch(const std::exception& e)
  {
    std::cout << "Not found..." << std::endl;
  }
  std::cout << "---------------------------------------------------------------------" << std::endl;
    
  std::cout << "Test4: Random number vector" << std::endl;
  try
  {
    srand(time(0));
    std::vector<int> d;
    std::vector<int> e;
    std::vector<int> f;
    for(int i = 0; i < 50; i++)
      d.push_back(rand() % 101);
    for(int i = 0; i < 50; i++)
      e.push_back(rand() % 101);
    for(int i = 0; i < 50; i++)
      f.push_back(rand() % 101);
    easyfind(d, rand() % 101);
    easyfind(e, rand() % 101);
    easyfind(f, rand() % 101);
    std::cout << "Wow, you are a super lucky person!!" << std::endl;
  }
  catch (const std::exception& e) 
  {
    std::cout << "Not found...but it doesn't mean you are unlucky" << std::endl;
  }
  std::cout << "---------------------------------------------------------------------" << std::endl;



  return 0;
}

