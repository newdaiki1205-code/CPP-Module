/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:51:57 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/18 08:19:07 by shiraishidais    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &container, int target) {
  typename T::iterator it;

  it = std::find(container.begin(), container.end(), target);
  if (it == container.end())
    throw std::logic_error("Not found...");
  return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int target) {
  typename T::const_iterator it;

  it = std::find(container.begin(), container.end(), target);
  if (it == container.end())
    throw std::logic_error("Not found...");
  return it;
}
