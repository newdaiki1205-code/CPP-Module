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

#include "Array.hpp"
#include <exception>
#include <iostream>
#include <string>

struct Test {
public:
  static int _construct;
  static int _bomb;
  Test() {
    if (_construct > _bomb)
      throw Bomb();
    _construct++;
  };
  ~Test() {};
  struct Bomb : public std::exception {
  public:
    const char *what() const throw() { return "BOOM!!!!!!"; }
  };
  Test &operator=(const Test &other) {
    (void)other;
    throw Bomb();
  }
  Test(const Test &other) {
    (void)other;
    throw Bomb();
  }
};

int Test::_construct = 0;
int Test::_bomb = 100;

int main(void) {
  std::cout << "Test1: Default Construction and set values, throwing exception"
            << std::endl;
  try {
    Array<int> a;
    std::cout << "size: " << a.size() << std::endl;
    a[0] = 1;
    std::cout << a[0] << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;

  std::cout << "Test2: Construction with parameter and set values" << std::endl;
  try {
    if (1) {
      std::cout << "Case with Array<int>" << std::endl;
      Array<int> b(5);
      std::cout << "size: " << b.size() << std::endl;
      std::cout << "Check Default Values" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << b[i] << " ";
      std::cout << std::endl;
      for (int i = 0; i < 5; i++)
        b[i] = i;
      std::cout << "Check Values after set" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << b[i] << " ";
      std::cout << std::endl;
    }
    if (1) {
      std::cout << std::endl;
      std::cout << "Case with const Array<int>" << std::endl;
      const Array<int> bb(5);
      std::cout << "size: " << bb.size() << std::endl;
      std::cout << "Check Default Values" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << bb[i] << " ";
      std::cout << std::endl;
      std::cout << "* const Array cannot set value" << std::endl;
      std::cout << std::endl;
    }
    if (1) {
      std::cout << "Case Array<string>" << std::endl;
      Array<std::string> bc(5);
      std::cout << "Check Default Values" << std::endl;
      for (unsigned int i = 0; i < bc.size(); i++) {
        std::cout << bc[i] << ", ";
      }
      std::cout << std::endl;
      for (unsigned int i = 0; i < bc.size(); i++) {
        char c = 'a' + i;
        bc[i] = c;
      }
      std::cout << "Check Default Values after set" << std::endl;
      for (unsigned int i = 0; i < bc.size(); i++) {
        std::cout << bc[i] << ", ";
      }
      std::cout << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;

  std::cout << "Test3: Construction with parameter and access to out of range"
            << std::endl;
  try {
    Array<float> c(5);
    std::cout << "size:" << c.size() << std::endl;
    std::cout << "Access index 100" << std::endl;
    std::cout << c[100];
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;
  std::cout << "Test3.2: Construction with parameter and access to out of range"
            << std::endl;
  try {
    Array<float> c(5);
    std::cout << "size:" << c.size() << std::endl;
    std::cout << "Access index -1" << std::endl;
    std::cout << c[-1];
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;
  std::cout << "Test3.3: Construction with parameter and access to out of range"
            << std::endl;
  try {
    Array<float> c(5);
    std::cout << "size:" << c.size() << std::endl;
    std::cout << "Access index " << c.size() << std::endl;
    c[c.size()];
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;

  std::cout << "Test4: Copy Construction" << std::endl;
  try {
    Array<int> d(5);
    for (int i = 0; i < 5; i++)
      d[i] = i;
    std::cout << "Check parent's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << d[i] << " ";
    std::cout << std::endl;

    Array<int> e(d);
    std::cout << "Check child's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << e[i] << " ";
    std::cout << std::endl;

    std::cout << "Modify and check parent's value" << std::endl;
    for (int i = 0; i < 5; i++)
      d[i] = i * 10;
    for (int i = 0; i < 5; i++)
      std::cout << d[i] << " ";
    std::cout << std::endl;

    std::cout << "Check child's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << e[i] << " ";
    std::cout << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;

  std::cout << "Test5: Copy Assignment Operator" << std::endl;
  try {
    Array<double> f;
    std::cout << std::endl;

    if (1) {
      Array<double> g(5);
      for (int i = 0; i < 5; i++)
        g[i] = 100 * i;
      std::cout << "Check parent's value" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << g[i] << " ";
      std::cout << std::endl;

      f = g;
      std::cout << "Check child's value" << std::endl;
      for (int i = 0; i < 5; i++)
        std::cout << f[i] << " ";
      std::cout << std::endl;

      std::cout << "Delete parent" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Check child's value" << std::endl;
    for (int i = 0; i < 5; i++)
      std::cout << f[i] << " ";
    std::cout << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;

  std::cout << "Test6: Error in copy assignment" << std::endl;
  try {
    Array<Test> h(5);
    Array<Test> i;

    i = h;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-------------------------------------------------------------"
            << std::endl;
  std::cout << "Test7: Error in new" << std::endl;
  try {
    Test::_construct = 0;
    Array<Test> j(5);
    Array<Test> k;
    Test::_construct = 0;
    Test::_bomb = 3;
    k = j;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
