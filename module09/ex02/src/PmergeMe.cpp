/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:55:10 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/10/04 23:38:38 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

PMerge::PMerge() : _compCounter(0), _dcompCounter(0) {}

PMerge::~PMerge() {}

PMerge::PMerge(const PMerge &other) {
  _vsorted = other._vsorted;
  _vunsorted = other._vunsorted;
  _dsorted = other._dsorted;
  _dunsorted = other._dunsorted;
  _compCounter = other._compCounter;
  _dcompCounter = other._dcompCounter;
  _size = other._size;
}

PMerge &PMerge::operator=(const PMerge &other) {
  if (this == &other)
    return (*this);
  _vsorted = other._vsorted;
  _vunsorted = other._vunsorted;
  _dsorted = other._dsorted;
  _dunsorted = other._dunsorted;
  _compCounter = other._compCounter;
  _dcompCounter = other._dcompCounter;
  _size = other._size;
  return (*this);
}

void printInfo(t_info *info) {
  std::vector<int>::iterator it;
  std::cout << "numElement: " << info->_numElement << std::endl;
  std::cout << "ignore: ";
  for (it = info->_ignore.begin(); it != info->_ignore.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "pend: ";
  for (it = info->_pend.begin(); it != info->_pend.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "main: ";
  for (it = info->_main.begin(); it != info->_main.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "indexArray: ";
  for (it = info->_indexArray.begin(); it != info->_indexArray.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PMerge::sortVector(char **input) {
  checkInput(input);
  _size = _vsorted.size();
  std::vector<int>::iterator it;
  sortOperation_recursive(0);
  d_sortOperation_recursive(0);

  std::vector<int>::iterator v_it;
  std::cout << "vector: count: " << _compCounter << " after sort: ";
  for (v_it = _vsorted.begin(); v_it != _vsorted.end(); ++v_it) {
    std::cout << *v_it << " ";
  }
  std::cout << std::endl;

  std::deque<int>::iterator d_it;
  std::cout << "deque: count: " << _dcompCounter << " after sort: ";
  for (d_it = _dsorted.begin(); d_it != _dsorted.end(); ++d_it) {
    std::cout << *d_it << " ";
  }
  std::cout << std::endl;
}

void PMerge::checkInput(char **input) {
  for (int i = 1; input[i]; i++) {
    _vunsorted.push_back(std::atoi(input[i]));
  }
  _vsorted = _vunsorted;

  for (int i = 1; input[i]; i++) {
    _dunsorted.push_back(std::atoi(input[i]));
  }
  _dsorted = _dunsorted;
}

void PMerge::sortOperation_recursive(int depth) {
  t_info info;
  info._numElement = pow(2, depth);
  if (swapPair(info))
    sortOperation_recursive(depth + 1);
  else
    return;
  prepInsertion(&info);
  mergeInsertion(&info);
}

void PMerge::prepInsertion(t_info *info) {
  std::vector<int>::iterator it;
  int rest = _size % info->_numElement;

  if (rest) {
    for (it = _vsorted.end() - rest; it != _vsorted.end(); ++it) {
      info->_ignore.push_back(*it);
    }
  }

  std::vector<int>::iterator border = _vsorted.end() - rest;

  it = _vsorted.begin() + info->_numElement * 2;
  if (std::distance(it, border) >= info->_numElement) {
    while (1) {
      info->_pend.insert(info->_pend.end(), it, it + info->_numElement);
      if (std::distance(it, border) <= info->_numElement * 2)
        break;
      it = it + info->_numElement * 2;
    }
  }

  info->_main.insert(info->_main.end(), _vsorted.begin(),
                     _vsorted.begin() + info->_numElement * 2);
  it = _vsorted.begin() + info->_numElement * 2;
  if (std::distance(it, border) >= info->_numElement * 2) {
    it = it + info->_numElement;
    while (1) {
      info->_main.insert(info->_main.end(), it, it + info->_numElement);
      if (std::distance(it, border) <= info->_numElement * 2)
        break;
      it = it + info->_numElement * 2;
    }
  }

  unsigned long i = info->_numElement * 2 - 1;
  while (i < info->_main.size()) {
    info->_indexArray.push_back(static_cast<int>(i));
    i = i + info->_numElement;
  }

  // printInfo(info);
}

void PMerge::mergeInsertion(t_info *info) {
  t_insert tool;

  tool._prevJN = 1;
  tool._baseJN = 3;
  tool._counter = 0;
  while (tool._counter < info->_pend.size() / info->_numElement) {
    if (info->_pend.size() / info->_numElement >= tool._baseJN - 1)
      tool._currentSearch_b = tool._baseJN;
    else
      tool._currentSearch_b = info->_pend.size() / info->_numElement + 1;
    while (tool._currentSearch_b > tool._prevJN) {
      sortByJacobsthal(info, &tool);
      tool._currentSearch_b--;
      tool._counter++;
    }
    renewJN(&tool);
  }
  info->_main.insert(info->_main.end(), info->_ignore.begin(),
                     info->_ignore.end());
  _vsorted = info->_main;
}

void PMerge::renewJN(t_insert *tool) {
  int oldJN = tool->_baseJN;

  tool->_baseJN = oldJN + tool->_prevJN * 2;
  tool->_prevJN = oldJN;
}

void PMerge::sortByJacobsthal(t_info *info, t_insert *tool) {
  int high_limit;
  if (info->_indexArray.size() >= tool->_currentSearch_b) {
    tool->_a_k = info->_indexArray[tool->_currentSearch_b - 1];
    high_limit = tool->_a_k - info->_numElement;
  } else
    high_limit = info->_main.size() - 1;

  int baseNum =
      info->_pend[(tool->_currentSearch_b - 1) * info->_numElement - 1];
  int startPos =
      info->_numElement * (tool->_currentSearch_b - 1) - info->_numElement;
  int insertPos =
      binarySearch(high_limit, baseNum, info->_main, info->_numElement);

  std::vector<int>::iterator pos = info->_main.begin() + insertPos;
  std::vector<int>::iterator first = info->_pend.begin() + startPos;
  std::vector<int>::iterator last =
      info->_pend.begin() + startPos + info->_numElement;
  info->_main.insert(pos, first, last);

  for (size_t i = 0; i < info->_indexArray.size(); i++) {
    if (info->_indexArray[i] >= insertPos) {
      info->_indexArray[i] += info->_numElement;
    }
  }
}

int PMerge::binarySearch(int bound, int baseNum, std::vector<int> &_main,
                         int _numElement) {
  int highUnit = (bound + 1) / _numElement;
  int lowUnit = 1;
  while (lowUnit <= highUnit) {
    int midUnit = (lowUnit + highUnit) / 2;
    int targetNum = _main[midUnit * _numElement - 1];
    if (baseNum > targetNum)
      lowUnit = midUnit + 1;
    else
      highUnit = midUnit - 1;
    _compCounter++;
  }
  return ((lowUnit - 1) * _numElement);
}

bool PMerge::swapPair(t_info info) {
  if (info._numElement * 2 > _size)
    return false;

  t_swap utils;
  utils._b = _vsorted.begin() + (info._numElement - 1);
  utils._a = utils._b + info._numElement;
  while (1) {
    _compCounter++;
    if (*utils._b > *utils._a) {
      utils._bHead = utils._b + 1 - info._numElement;
      utils._aHead = utils._a + 1 - info._numElement;
      std::swap_ranges(utils._bHead, utils._b + 1, utils._aHead);
    }
    if (std::distance(utils._a, _vsorted.end()) < info._numElement * 2 + 1)
      break;
    utils._b = utils._b + info._numElement * 2;
    utils._a = utils._a + info._numElement * 2;
  }
  return (true);
}

void PMerge::d_sortOperation_recursive(int depth) {
  t_dinfo info;
  info._numElement = pow(2, depth);
  if (d_swapPair(info))
    d_sortOperation_recursive(depth + 1);
  else
    return;
  d_prepInsertion(&info);
  d_mergeInsertion(&info);
}

void PMerge::d_prepInsertion(t_dinfo *info) {
  std::deque<int>::iterator it;
  int rest = _size % info->_numElement;

  if (rest) {
    for (it = _dsorted.end() - rest; it != _dsorted.end(); ++it) {
      info->_ignore.push_back(*it);
    }
  }

  std::deque<int>::iterator border = _dsorted.end() - rest;

  it = _dsorted.begin() + info->_numElement * 2;
  if (std::distance(it, border) >= info->_numElement) {
    while (1) {
      info->_pend.insert(info->_pend.end(), it, it + info->_numElement);
      if (std::distance(it, border) <= info->_numElement * 2)
        break;
      it = it + info->_numElement * 2;
    }
  }

  info->_main.insert(info->_main.end(), _dsorted.begin(),
                     _dsorted.begin() + info->_numElement * 2);
  it = _dsorted.begin() + info->_numElement * 2;
  if (std::distance(it, border) >= info->_numElement * 2) {
    it = it + info->_numElement;
    while (1) {
      info->_main.insert(info->_main.end(), it, it + info->_numElement);
      if (std::distance(it, border) <= info->_numElement * 2)
        break;
      it = it + info->_numElement * 2;
    }
  }

  unsigned long i = info->_numElement * 2 - 1;
  while (i < info->_main.size()) {
    info->_indexArray.push_back(static_cast<int>(i));
    i = i + info->_numElement;
  }

  // printInfo(info);
}

void PMerge::d_mergeInsertion(t_dinfo *info) {
  t_insert tool;

  tool._prevJN = 1;
  tool._baseJN = 3;
  tool._counter = 0;
  while (tool._counter < info->_pend.size() / info->_numElement) {
    if (info->_pend.size() / info->_numElement >= tool._baseJN - 1)
      tool._currentSearch_b = tool._baseJN;
    else
      tool._currentSearch_b = info->_pend.size() / info->_numElement + 1;
    while (tool._currentSearch_b > tool._prevJN) {
      d_sortByJacobsthal(info, &tool);
      tool._currentSearch_b--;
      tool._counter++;
    }
    d_renewJN(&tool);
  }
  info->_main.insert(info->_main.end(), info->_ignore.begin(),
                     info->_ignore.end());
  _dsorted = info->_main;
}

void PMerge::d_renewJN(t_insert *tool) {
  int oldJN = tool->_baseJN;

  tool->_baseJN = oldJN + tool->_prevJN * 2;
  tool->_prevJN = oldJN;
}

void PMerge::d_sortByJacobsthal(t_dinfo *info, t_insert *tool) {
  int high_limit;
  if (info->_indexArray.size() >= tool->_currentSearch_b) {
    tool->_a_k = info->_indexArray[tool->_currentSearch_b - 1];
    high_limit = tool->_a_k - info->_numElement;
  } else
    high_limit = info->_main.size() - 1;

  int baseNum =
      info->_pend[(tool->_currentSearch_b - 1) * info->_numElement - 1];
  int startPos =
      info->_numElement * (tool->_currentSearch_b - 1) - info->_numElement;
  int insertPos =
      d_binarySearch(high_limit, baseNum, info->_main, info->_numElement);

  std::deque<int>::iterator pos = info->_main.begin() + insertPos;
  std::deque<int>::iterator first = info->_pend.begin() + startPos;
  std::deque<int>::iterator last =
      info->_pend.begin() + startPos + info->_numElement;
  info->_main.insert(pos, first, last);

  for (size_t i = 0; i < info->_indexArray.size(); i++) {
    if (info->_indexArray[i] >= insertPos) {
      info->_indexArray[i] += info->_numElement;
    }
  }
}

int PMerge::d_binarySearch(int bound, int baseNum, std::deque<int> &_main,
                           int _numElement) {
  int highUnit = (bound + 1) / _numElement;
  int lowUnit = 1;
  while (lowUnit <= highUnit) {
    int midUnit = (lowUnit + highUnit) / 2;
    int targetNum = _main[midUnit * _numElement - 1];
    if (baseNum > targetNum)
      lowUnit = midUnit + 1;
    else
      highUnit = midUnit - 1;
    _dcompCounter++;
  }
  return ((lowUnit - 1) * _numElement);
}

bool PMerge::d_swapPair(t_dinfo info) {
  if (info._numElement * 2 > _size)
    return false;

  t_dswap utils;
  utils._b = _dsorted.begin() + (info._numElement - 1);
  utils._a = utils._b + info._numElement;
  while (1) {
    _dcompCounter++;
    if (*utils._b > *utils._a) {
      utils._bHead = utils._b + 1 - info._numElement;
      utils._aHead = utils._a + 1 - info._numElement;
      std::swap_ranges(utils._bHead, utils._b + 1, utils._aHead);
    }
    if (std::distance(utils._a, _dsorted.end()) < info._numElement * 2 + 1)
      break;
    utils._b = utils._b + info._numElement * 2;
    utils._a = utils._a + info._numElement * 2;
  }
  return (true);
}
