/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 11:42:23 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/19 11:49:00 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

#define RANGE RAND_MAX

std::set<int> numGenerator(unsigned int size) {
  std::set<int> ret;
  int value;

  for (unsigned int i = 0; i < size; i++) {
    value = rand() % RANGE;
    if (rand() % 2)
      value = value * -1;
    ret.insert(value);
  }
  return ret;
}

int main(void) {
  srand(time(0));
  std::cout << "Test1: test from subject, output shoud be 2 and 14"
            << std::endl;
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test2: INT_MAX, INT_MIN and 0" << std::endl;
  try {
    Span sp = Span(100);
    sp.addNumber(0);
    sp.addNumber(INT_MAX);
    sp.addNumber(INT_MIN);
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test3: container size 10000" << std::endl;
  try {
    Span a(10000);

    std::vector<int> test;
    for (int i = 0; i < 10000; i++) {
      test.push_back(i);
    }
    a.addNumbers(test.begin(), test.end());
    std::cout << "longestSpan: " << a.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << a.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test3.2: container size 100000 with random numbers"
            << std::endl;
  try {
    Span b(100000);
    std::set<int> bb = numGenerator(100000);
    b.addNumbers(bb.begin(), bb.end());

    std::cout << "longestSpan: " << b.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << b.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test4: Copy Construction" << std::endl;
  try {
    Span c(100);
    for (int i = 0; i < 10; i++)
      c.addNumber(i);
    std::cout << "Numbers in original container" << std::endl;
    c.show();
    std::cout << std::endl;

    Span d(c);
    std::cout << "Numbers in copy container" << std::endl;
    d.show();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test5: Copy Assignement operator" << std::endl;
  try {
    Span e(100);
    for (int i = 0; i < 10; i++)
      e.addNumber(i);
    std::cout << "Numbers in original container" << std::endl;
    e.show();
    std::cout << std::endl;

    Span f(100);
    for (int i = 0; i < 10; i++)
      f.addNumber(i + 10);
    std::cout << "Numbers before copy Assignement" << std::endl;
    f.show();
    std::cout << std::endl;

    f = e;
    std::cout << "Numbers after copy Assignement" << std::endl;
    f.show();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test6: Error Handling (No space in container)" << std::endl;
  try {
    Span g(5);

    for (int i = 0; i < 5; i++)
      g.addNumber(i);
    g.sizeInfo();
    std::cout << "Try one more call addNumber" << std::endl;
    g.addNumber(100);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test7: Error Handling (No longestSpan)" << std::endl;
  try {
    Span h(1);

    h.addNumber(100);
    h.sizeInfo();
    std::cout << "Call longestSpan()" << std::endl;
    h.longestSpan();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  std::cout << "Test8: Error Handling (No shortestSpan)" << std::endl;
  try {
    Span i(1);

    i.addNumber(100);
    i.sizeInfo();
    std::cout << "Call shortestSpan()" << std::endl;
    i.shortestSpan();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "---------------------------------------------------------------"
               "--------"
            << std::endl;

  return 0;
}
