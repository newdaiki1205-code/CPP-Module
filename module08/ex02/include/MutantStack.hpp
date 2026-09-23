/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:13:05 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/21 18:05:09 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  MutantStack();
  ~MutantStack();
  MutantStack(const MutantStack& other);
  MutantStack& operator=(const MutantStack& other);

  typedef typename Container::iterator iterator;

  iterator begin();
  iterator end();
};

#include "MutantStack.tpp"

#endif  // !MUTANTSTACK_HPP
