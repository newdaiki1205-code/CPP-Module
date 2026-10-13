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
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(void) {
  std::cout << "Test1: Simple vector and Error test" << std::endl;
  try {
    std::vector<int> a;
    std::cout << "Create vector (0-4)" << std::endl;
    for (int i = 0; i < 5; i++)
      a.push_back(i);
    std::cout << "Searching 1 in the given container..." << std::endl;
    std::vector<int>::iterator it = easyfind(a, 1);
    std::cout << *it << " was found in the index "
              << std::distance(a.begin(), it) << std::endl;
    std::cout << "Reverse Sort" << std::endl;
    std::sort(a.rbegin(), a.rend());
    std::cout << "Searching 1 in the given container..." << std::endl;
    it = easyfind(a, 1);
    std::cout << *it << " was found in the index "
              << std::distance(a.begin(), it) << std::endl;
    std::cout << "Change values (5-9)" << std::endl;
    for (int i = 0; i < 5; i++)
      a.at(i) = i + 5;
    std::cout << "Searching 1 in the given container..." << std::endl;
    it = easyfind(a, 1);
    std::cout << *it << " was found in the index "
              << std::distance(a.begin(), it) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout
      << "---------------------------------------------------------------------"
      << std::endl;

  std::cout << "Test2: Simple list and Error test" << std::endl;
  try {
    std::list<int> b;
    std::cout << "Create list (0-4)" << std::endl;
    for (int i = 0; i < 5; i++)
      b.push_back(i);
    std::cout << "Searching 4 in the given container..." << std::endl;
    std::list<int>::iterator it = easyfind(b, 4);
    std::cout << *it << " was found in the index "
              << std::distance(b.begin(), it) << std::endl;
    std::cout << "Delete elements and insert the same values in opposit oder"
              << std::endl;
    for (int i = 0; i < 5; i++)
      b.pop_back();
    if (b.empty())
      std::cout << "list is empty" << std::endl;
    for (int i = 0; i < 5; i++)
      b.push_front(i);
    std::cout << "Searching 4 in the given container..." << std::endl;
    it = easyfind(b, 4);
    std::cout << *it << " was found in the index "
              << std::distance(b.begin(), it) << std::endl;
    std::cout << "Delete the first value(4)" << std::endl;
    b.pop_front();
    std::cout << "Searching 4 in the given container..." << std::endl;
    it = easyfind(b, 4);
    std::cout << *it << " was found in the index "
              << std::distance(b.begin(), it) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout
      << "---------------------------------------------------------------------"
      << std::endl;

  std::cout << "Test3: Check if easyfind finds the first occurrence"
            << std::endl;
  try {
    std::vector<int> c;
    std::cout << "Create vector (0-4)" << std::endl;
    for (int i = 0; i < 5; i++)
      c.push_back(i);
    std::cout << "Add 1 at the last" << std::endl;
    c.push_back(1);
    std::cout << "Searching 1 in the given container..." << std::endl;
    std::vector<int>::iterator it = easyfind(c, 1);
    std::cout << *it << " was found in the index "
              << std::distance(c.begin(), it) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout
      << "---------------------------------------------------------------------"
      << std::endl;

  std::cout << "Test4: const vector" << std::endl;
  try {
    std::cout << "Make const vector with values(0-4)" << std::endl;
    std::vector<int> test;
    for (int i = 0; i < 5; i++) {
      test.push_back(i);
    }
    const std::vector<int> con(test.begin(), test.end());
    std::cout << "Searching 1 in the given container..." << std::endl;
    std::vector<int>::const_iterator it = easyfind(con, 1);
    std::vector<int>::const_iterator begin = con.begin();
    std::cout << *it << " was found in the index " << std::distance(begin, it)
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout
      << "---------------------------------------------------------------------"
      << std::endl;
  std::cout << "Test5: empty container" << std::endl;
  try {
    std::vector<int> emp;
    if (emp.empty())
      std::cout << "container is empty" << std::endl;
    std::cout << "Searching 1 in the given container..." << std::endl;
    std::vector<int>::iterator it = easyfind(emp, 1);
    std::cout << *it << " was found in the index "
              << std::distance(emp.begin(), it) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout
      << "---------------------------------------------------------------------"
      << std::endl;
  std::cout << "Test6: check if easyfind return iterator" << std::endl;
  try {
    std::vector<int> foo;
    std::cout << "Container has: ";
    for (int i = 0; i < 5; i++) {
      foo.push_back(i);
      std::cout << foo[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "modify value..." << std::endl;
    *(easyfind(foo, 1)) = 100;
    std::cout << "Searching 100 in the given container..." << std::endl;
    std::vector<int>::iterator it = easyfind(foo, 100);
    std::cout << *it << " was found in the index "
              << std::distance(foo.begin(), it) << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
