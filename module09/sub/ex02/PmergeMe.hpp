/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:20:38 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/10/04 20:39:11 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <ctime>
#include <deque>
#include <exception>
#include <vector>

typedef struct s_info {
  int _numElement;
  std::vector<int> _main;
  std::vector<int> _pend;
  std::vector<int> _ignore;
  std::vector<int> _indexArray;
} t_info;

typedef struct s_swap {
  std::vector<int>::iterator _b;
  std::vector<int>::iterator _a;
  std::vector<int>::iterator _bHead;
  std::vector<int>::iterator _aHead;
} t_swap;

typedef struct s_dinfo {
  int _numElement;
  std::deque<int> _main;
  std::deque<int> _pend;
  std::deque<int> _ignore;
  std::deque<int> _indexArray;
} t_dinfo;

typedef struct s_dswap {
  std::deque<int>::iterator _b;
  std::deque<int>::iterator _a;
  std::deque<int>::iterator _bHead;
  std::deque<int>::iterator _aHead;
} t_dswap;

typedef struct s_insert {
  size_t _currentSearch_b;
  size_t _baseJN;
  size_t _prevJN;
  int _a_k;
  size_t _counter;
} t_insert;

class PMerge {
private:
  std::vector<int> _vunsorted;
  std::vector<int> _vsorted;
  std::deque<int> _dunsorted;
  std::deque<int> _dsorted;
  int _compCounter;
  int _dcompCounter;
  int _size;
  clock_t _vStart;
  clock_t _vEnd;
  clock_t _dStart;
  clock_t _dEnd;

  void checkInput(char **input);
  void sortVector(char **input);
  void sortDeque(char **input);
  void printMessage();

  double measureTime(clock_t _start, clock_t _end);

  void prepVdata(char **input);
  void sortOperation_recursive(int depth);
  bool swapPair(t_info info);
  void prepInsertion(t_info *info);
  void mergeInsertion(t_info *info);
  void sortByJacobsthal(t_info *info, t_insert *tool);
  void renewJN(t_insert *tool);
  int binarySearch(int bound, int baseNum, std::vector<int> &_main,
                   int _numElement);

  void prepDdata(char **input);
  void d_sortOperation_recursive(int depth);
  bool d_swapPair(t_dinfo info);
  void d_prepInsertion(t_dinfo *info);
  void d_mergeInsertion(t_dinfo *info);
  void d_sortByJacobsthal(t_dinfo *info, t_insert *tool);
  void d_renewJN(t_insert *tool);
  int d_binarySearch(int bound, int baseNum, std::deque<int> &_main,
                     int _numElement);

public:
  PMerge();
  ~PMerge();
  PMerge(const PMerge &other);
  PMerge &operator=(const PMerge &other);

  void PmergeMe(char **input);

  class InvalidCharacter : public std::exception {
    const char *what() const throw();
  };

  class StackOverflow : public std::exception {
    const char *what() const throw();
  };

  class NegativeValue : public std::exception {
    const char *what() const throw();
  };

  class Duplication : public std::exception {
    const char *what() const throw();
  };
};

#endif // !PMERGEME_HPP
