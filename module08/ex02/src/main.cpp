/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:01:20 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/21 18:03:50 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <list>

#include "../include/MutantStack.hpp"

int main() {
  std::cout << "Test1: Test from Subject + check copy" << std::endl;
  try {
    MutantStack<int> mstack;
    std::cout << "Test push() in MutantStack (pushing 5 and 17)" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Test top() in MutantStack" << std::endl;
    std::cout << mstack.top() << std::endl;
    std::cout << "Test pop() and size() in MutantStack" << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Print out elements in MutantStack with iterator (start from "
                 "the first element)"
              << std::endl;
    while (it != ite) {
      std::cout << *it << " ";
      ++it;
    }
    std::cout << std::endl;
    std::cout << "Copy MutantStack to stack and print out element with top() "
                 "and pop() (start from the last element)"
              << std::endl;
    std::stack<int> s(mstack);
    while (!s.empty()) {
      std::cout << s.top() << " ";
      s.pop();
    }
    std::cout << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout
      << "--------------------------------------------------------------------"
      << std::endl;

  std::cout << "Test2: Replace MutantStack with std::list" << std::endl;
  try {
    std::list<int> testlist;
    std::cout << "Test push_back() in testlist (push_backing 5 and 17)"
              << std::endl;
    testlist.push_back(5);
    testlist.push_back(17);
    std::cout << "Test top() in testlist" << std::endl;
    std::cout << testlist.back() << std::endl;
    std::cout << "Test pop() and size() in testlist" << std::endl;
    testlist.pop_back();
    std::cout << testlist.size() << std::endl;
    testlist.push_back(3);
    testlist.push_back(5);
    testlist.push_back(737);
    testlist.push_back(0);
    std::list<int>::iterator it = testlist.begin();
    std::list<int>::iterator ite = testlist.end();
    ++it;
    --it;
    std::cout << "Print out elements in testlist with iterator (start from "
                 "the first element)"
              << std::endl;
    while (it != ite) {
      std::cout << *it << " ";
      ++it;
    }
    std::cout << std::endl;
    std::cout << "Copy testlist to stack and print out element with top() "
                 "and pop() (start from the last element)"
              << std::endl;
    std::stack<int, std::list<int> > cp(testlist);
    while (!cp.empty()) {
      std::cout << cp.top() << " ";
      cp.pop();
    }
    std::cout << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
