/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:53:22 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/23 20:17:35 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T> typename T::iterator easyfind(T &container, int target);
template <typename T>
typename T::const_iterator easyfind(const T &container, int target);

#include "easyfind.tpp"

#endif // !EASYFIND_HPP
