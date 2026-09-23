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

template <typename T>
void easyfind(T container, int target)
{
  typename T::iterator it;

  std::cout << "Searching " << target << " in the given container..." << std::endl;
  it = std::find(container.begin(), container.end(), target);
  if(it == container.end())
    throw NotFound();
  std::cout << target << " was found in index number " << std::distance(container.begin(), it) << std::endl;
}

